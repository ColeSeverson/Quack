//
// Created by Michal Young on 9/12/18.
//

#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>
#include <sstream>
#include <vector>

namespace AST {
    // Abstract syntax tree.  ASTNode is abstract base class for all other nodes.

    //Enums for keeping track of statement types;
    enum statementEnum {
        ASSIGN,
        ASSIGNDECLARE,
        EXPR,
        RETURN,
        IF,
        WHILE,
        LOAD,
        INTCONST,
        STRINGCONST,
        CALL,
        OOF
    };

    // Json conversion and pretty-printing can pass around a print context object
    // to keep track of indentation, and possibly other things.
    class AST_print_context {
    public:
        int indent_; // Number of spaces to place on left, after each newline
        AST_print_context() : indent_{0} {};
        void indent() { ++indent_; }
        void dedent() { --indent_; }
    };

    class ASTNode {
    public:
        virtual void json(std::ostream& out, AST_print_context& ctx) = 0;  // Json string representation
        std::string str() {
            std::stringstream ss;
            AST_print_context ctx;
            json(ss, ctx);
            return ss.str();
        }
    protected:
        void json_indent(std::ostream& out, AST_print_context& ctx);
        void json_head(std::string node_kind, std::ostream& out, AST_print_context& ctx);
        void json_close(std::ostream& out, AST_print_context& ctx);
        void json_child(std::string field, ASTNode& child, std::ostream& out, AST_print_context& ctx, char sep=',');
    };

    class Stub : public ASTNode {
        std::string name_;
    public:
        explicit Stub(std::string name) : name_{name} {}
        void json(std::ostream& out, AST_print_context& ctx) override;
        //Shouldn't ever need this since it should error out before static semantics at this point
        std::string getName() {return this->name_;};
    };


    /*
     * Abstract base class for nodes that have sequences
     * of children, e.g., block of statements, sequence of
     * classes.  These may be able to share some operations,
     * especially when applying a method to the sequence just
     * means applying the method to each element of the sequence.
     * We need a different kind of sequence depending on type of
     * elements if we want to access elements without casting while
     * still having access to their fields.
     * (Will replace 'Seq')
     */
    template<class Kind>
    class Seq : public ASTNode {
    protected:
        std::string kind_;
        std::vector<Kind *> elements_;
    public:
        Seq(std::string kind) : kind_{kind}, elements_{std::vector<Kind *>()} {}

        void append(Kind *el) { elements_.push_back(el); }

        void json(std::ostream &out, AST_print_context &ctx) {
            json_head(kind_, out, ctx);
            out << "\"elements_\" : [";
            auto sep = "";
            for (Kind *el: elements_) {
                out << sep;
                el->json(out, ctx);
                sep = ", ";
            }
            out << "]";
            json_close(out, ctx);
        }

        std::vector<Kind *> getElements() {
            return this->elements_;
        }

    };

    /* L_Expr nodes are AST nodes that can be evaluated for location.
     * Most can also be evaluated for value_.  An example of an L_Expr
     * is an identifier, which can appear on the left_ hand or right_ hand
     * side of an assignment.  For example, in x = y, x is evaluated for
     * location and y is evaluated for value_.
     *
     * For now, a location is just a name, because that's what we index
     * the symbol table with.  In a full compiler, locations can be
     * more complex, and typically in code generation we would have
     * LExpr evaluate to an address in a register.
     */
    enum lexprTypes {
        IDENT,
        DOT,
        NONE
    };
    class LExpr : public ASTNode {
        protected:
            lexprTypes ltype = NONE;
        public:
            lexprTypes getType() {return this->ltype;};
        /* Abstract base class */
    };


    /* Identifiers like x and literals like 42 are the
    * leaves of the AST.  A literal can only be evaluated
    * for value_ (the 'eval' method), but an identifier
    * can also be evaluated for location (when we want to
    * store something in it).
    */
    class Ident : public LExpr {
        std::string text_;
    public:
        explicit Ident(std::string txt) : text_{txt} {
            this->ltype = IDENT;
        }
        void json(std::ostream& out, AST_print_context& ctx) override;
        std::string getText() {return this->text_;};
    };


    /* A block is a sequence of statements or expressions.
     * For simplicity we'll just make it a sequence of ASTNode,
     * and leave it to the parser to build valid structures.
     */
    class Block : public Seq<ASTNode> {
    public:
        explicit Block() : Seq("Block") {}
     };



    /* Formal arguments list is a list of
     * identifier: type pairs.
     */
    class Formal : public ASTNode {
        Ident& var_;
        Ident& type_;
    public:
        explicit Formal(Ident& var, Ident& type_) :
            var_{var}, type_{type_} {};
        void json(std::ostream& out, AST_print_context&ctx) override;
        Ident * getName() {return &this->var_;};
        Ident * getType() {return &this->type_;};
    };

    class Formals : public Seq<Formal> {
    public:
        explicit Formals() : Seq("Formals") {}
    };

    class Method : public ASTNode {
        Ident& name_;
        Formals& formals_;
        Ident& returns_;
        Block& statements_;
    public:
        explicit Method(Ident& name, Formals& formals, Ident& returns, Block& statements) :
          name_{name}, formals_{formals}, returns_{returns}, statements_{statements} {}
        void json(std::ostream& out, AST_print_context&ctx) override;
        Ident * getName() {return &this->name_;};
        Formals * getFormals() {return &this->formals_;};
        Ident * getReturnType() {return &this->returns_;};
        Block * getStatements() {return &this->statements_;};
    };

    class Methods : public Seq<Method> {
    public:
        explicit Methods() : Seq("Methods") {}
    };




    /* An assignment has an lvalue (location to be assigned to)
     * and an expression.  We evaluate the expression and place
     * the value_ in the variable.  An assignment may also place a
     * static type constraint on a variable.  This is logically a
     * distinct operation, and could be represented as a separate statement,
     * but it's convenient to keep it in the assignment since our syntax
     * puts it there.
     */

    class Statement : public ASTNode { 
        protected:
            statementEnum type = OOF;
        public:
            statementEnum getType() {return this->type;};
    };

    /* A statement could be just an expression ... but
     * we might want to interpose a node here.
     */
    class Expr : public Statement { 
        public:
            explicit Expr() {
                type = EXPR;
            }
    };

    class Assign : public Statement {
    protected:  // But inherited by AssignDeclare
        ASTNode &lexpr_;
        ASTNode &rexpr_;
    public:
        explicit Assign(ASTNode &lexpr, ASTNode &rexpr) :
           lexpr_{lexpr}, rexpr_{rexpr} {
               this->type = ASSIGN;
           }
        void json(std::ostream& out, AST_print_context& ctx) override;
        LExpr * getLexpr() {return dynamic_cast<LExpr *>(&this->lexpr_);};
        Statement * getExpr() {return dynamic_cast<Statement *>(&this->rexpr_);};
    };

    class AssignDeclare : public Statement {
    protected:
        Ident &static_type_;
        ASTNode &lexpr_;
        ASTNode &rexpr_;
    public:
        explicit AssignDeclare(ASTNode &lexpr, ASTNode &rexpr, Ident &static_type) :
             lexpr_{lexpr}, rexpr_{rexpr}, static_type_{static_type} {
                this->type = ASSIGNDECLARE;
            }
        void json(std::ostream& out, AST_print_context& ctx) override;
        Ident * getStaticType() {return &this->static_type_;};
        LExpr * getLexpr() {return dynamic_cast<LExpr *>(&this->lexpr_);};
        Statement * getExpr() {return dynamic_cast<Statement *>(&this->rexpr_);};

    };


    /* When an expression is an LExpr, we
     * the LExpr denotes a location, and we
     * need to load it.
     */
    class Load : public Expr {
        LExpr &loc_;
    public:
        Load(LExpr &loc) : loc_{loc} {
            this->type = LOAD;
        }
        void json(std::ostream &out, AST_print_context &ctx) override;
        LExpr * getLocation() {return &this->loc_;};
    };



    /* 'return' statement returns value from method */
    class Return : public Statement {
        ASTNode &expr_;
    public:
        explicit Return(ASTNode& expr) : expr_{expr}  {
            this->type = RETURN;
        }
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getExpr() {return dynamic_cast<Expr *>(&this->expr_);};
    };

    class If : public Statement {
        ASTNode &cond_; // The boolean expression to be evaluated
        Seq<ASTNode> &truepart_; // Execute this block if the condition is true
        Seq<ASTNode> &falsepart_; // Execute this block if the condition is false
    public:
        explicit If(ASTNode& cond, Seq<ASTNode>& truepart, Seq<ASTNode>& falsepart) :
            cond_{cond}, truepart_{truepart}, falsepart_{falsepart} {
                this->type = IF;
             };
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getCondition() {return dynamic_cast<Expr *>(&this->cond_);};
        Seq<ASTNode> * getTrueBlock() {return &this->truepart_;};
        Seq<ASTNode> * getFalseBlock() {return &this->falsepart_;};
    };

    class While : public Statement {
        ASTNode& cond_;  // Loop while this condition is true
        Seq<ASTNode>&  body_;     // Loop body
    public:
        explicit While(ASTNode& cond, Block& body) :
            cond_{cond}, body_{body} { 
                this->type = WHILE;
            };
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getCondition() {return dynamic_cast<Expr *>(&this->cond_);};
        Seq<ASTNode> * getBody() {return &this->body_;};
    };




    /* A class has a name, a list of arguments, and a body
    * consisting of a block (essentially the constructor)
    * and a list of methods.
    */
    class Class : public ASTNode {
        Ident& name_;
        Ident& super_;
        Method& constructor_;
        Methods& methods_;
    public:
        explicit Class(Ident& name, Ident& super,
                 Method& constructor, Methods& methods) :
            name_{name},  super_{super},
            constructor_{constructor}, methods_{methods} {};
        void json(std::ostream& out, AST_print_context& ctx) override;
        Ident* getName() {return &this->name_;};
        Ident* getSuper() {return &this->super_;};
        Method* getConstructor() {return &this->constructor_;};
        Methods* getMethods() {return &this->methods_;};
    };

    /* A Quack program begins with a sequence of zero or more
     * class definitions.
     */
    class Classes : public Seq<Class> {
    public:
        explicit Classes() : Seq<Class>("Classes") {}
    };

    class IntConst : public Expr {
        int value_;
    public:
        explicit IntConst(int v) : value_{v} {
            this->type = INTCONST;
        }
        void json(std::ostream& out, AST_print_context& ctx) override;
        int getValue() {return value_;};
    };

    class Type_Alternative : public ASTNode {
        Ident& ident_;
        Ident& classname_;
        Block& block_;
    public:
        explicit Type_Alternative(Ident& ident, Ident& classname, Block& block) :
                ident_{ident}, classname_{classname}, block_{block} {}
        void json(std::ostream& out, AST_print_context& ctx) override;
        Ident * getIdent() {return &this->ident_;};
        Ident * getClassName() {return &this->classname_;};
        Block * getStatements() {return &this->block_;};
    };

    class Type_Alternatives : public Seq<Type_Alternative> {
    public:
        explicit Type_Alternatives() : Seq("Type_Alternatives") {}
    };

    class Typecase : public Statement {
        Expr& expr_; // An expression we want to downcast to a more specific class
        Type_Alternatives& cases_;    // A case for each potential type
    public:
        explicit Typecase(Expr& expr, Type_Alternatives& cases) :
                expr_{expr}, cases_{cases} {};
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getExpression() {return &this->expr_;};
        Type_Alternatives * getAlternatives() {return &this->cases_;};
    };


    class StrConst : public Expr {
        std::string value_;
    public:
        explicit StrConst(std::string v) : value_{v} {
            this->type = STRINGCONST;
        }
        void json(std::ostream& out, AST_print_context& ctx) override;
        std::string getValue(){return value_;};
    };

    class Actuals : public Seq<Expr> {
    public:
        explicit Actuals() : Seq("Actuals") {}
    };


    /* Constructors are different from other method calls. They
      * are static (not looked up in the vtable), have no receiver
      * object, and have their own type-checking rules.
      */
    class Construct : public Expr {
        Ident&  method_;           /* Method name is same as class name */
        Actuals& actuals_;    /* Actual arguments to constructor */
    public:
        explicit Construct(Ident& method, Actuals& actuals) :
                method_{method}, actuals_{actuals} {}
        void json(std::ostream& out, AST_print_context& ctx) override;
        Ident * getName() {return &this->method_;};
        Actuals * getArgs() {return &this->actuals_;};
    };


    /* Method calls are central to type checking and code
     * generation ... and for us, the operators +, -, etc
     * are method calls to specially named methods.
     */
    class Call : public Expr {
        Expr& receiver_;        /* Expression computing the receiver object */
        Ident& method_;         /* Identifier of the method */
        Actuals& actuals_;     /* List of actual arguments */
    public:
        explicit Call(Expr& receiver, Ident& method, Actuals& actuals) :
                receiver_{receiver}, method_{method}, actuals_{actuals} {
                    this->type = CALL;
                };
        // Convenience factory for the special case of a method
        // created for a binary operator (+, -, etc).
        static Call* binop(std::string opname, Expr& receiver, Expr& arg);
        void json(std::ostream& out, AST_print_context& ctx) override;
        Ident * getMethod(){return &this->method_;};
        Actuals * getArgs(){return &this->actuals_;};
        //This should be a class... right?
        Expr * getReciever(){return &this->receiver_;};
    };


    // Virtual base class for binary operations.
    // Does NOT include +, -, *, /, etc, which
    // are method calls.
    // Does include And, Or, Dot, ...
   class BinOp : public Expr {
    protected:
        std::string opsym;
        ASTNode &left_;
        ASTNode &right_;
        BinOp(std::string sym, ASTNode &l, ASTNode &r) :
                opsym{sym}, left_{l}, right_{r} {};
    public:
        void json(std::ostream& out, AST_print_context& ctx) override;
        std::string getSymbol() {return this->opsym;};
        Expr * getLeft(){return dynamic_cast<Expr *>(&this->left_);};
        Expr * getRight(){return dynamic_cast<Expr *>(&this->right_);};
    };

   class And : public BinOp {
   public:
       explicit And(ASTNode& left, ASTNode& right) :
          BinOp("And", left, right) {}
   };

    class Or : public BinOp {
    public:
        explicit Or(ASTNode& left, ASTNode& right) :
                BinOp("Or", left, right) {}
    };

    class Not : public Expr {
        ASTNode& left_;
    public:
        explicit Not(ASTNode& left ):
            left_{left}  {}
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getLeft(){return dynamic_cast<Expr *>(&this->left_);};
    };


    /* Can a field de-reference (expr . IDENT) be a binary
     * operation?  It can be evaluated to a location (l_exp),
     * whereas an operation like * and + cannot, but maybe that's
     * ok.  We'll tentatively group it with Binop and consider
     * changing it later if we need to make the distinction.
     */

    class Dot : public LExpr {
        Expr& left_;
        Ident& right_;
    public:
        explicit Dot (Expr& left, Ident& right) :
           left_{left},  right_{right} {
               this->ltype = DOT;
           }
        void json(std::ostream& out, AST_print_context& ctx) override;
        Expr * getLeft() {return &this->left_;};
        Ident * getRight() {return &this->right_;};
    };


    /* A program has a set of classes (in any order) and a block of
     * statements.
     */
    class Program : public ASTNode {
    public:
        Classes& classes_;
        Block& statements_;
        explicit Program(Classes& classes, Block& statements) :
                classes_{classes}, statements_{statements} {}
        void json(std::ostream& out, AST_print_context& ctx) override;
    };



}
#endif //ASTNODE_H
