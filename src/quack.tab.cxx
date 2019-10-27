// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "quack.tab.hxx"


// Unqualified %code blocks.
#line 29 "quack.yxx" // lalr1.cc:435

    #include "lex.yy.h"
    #undef yylex
    #define yylex lexer.yylex  /* Within bison's parse() we should invoke lexer.yylex(), not the global yylex() */
    void dump(AST::ASTNode* n);


#line 53 "quack.tab.cxx" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 148 "quack.tab.cxx" // lalr1.cc:510

  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 144 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.node) = new AST::Program(*(yystack_[1].value.classes), *(yystack_[0].value.block));
          // std::cerr << "Transmitting root to driver\n";
          *root = (yylhs.value.node); // Transmit tree back to driver
          // std::cerr << "Transmitted root to driver\n";
        }
#line 596 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 3:
#line 154 "quack.yxx" // lalr1.cc:919
    {  (yylhs.value.classes) = new AST::Classes(); }
#line 602 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 4:
#line 155 "quack.yxx" // lalr1.cc:919
    {  (yylhs.value.classes) = (yystack_[1].value.classes); (yylhs.value.classes)->append((yystack_[0].value.klass)); }
#line 608 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 5:
#line 160 "quack.yxx" // lalr1.cc:919
    { AST::ASTNode* constructor = new AST::Method(*(yystack_[8].value.ident), *(yystack_[6].value.formals), *(yystack_[8].value.ident), *(yystack_[2].value.block));
	  (yylhs.value.klass) = new AST::Class(*(yystack_[8].value.ident), *(yystack_[4].value.ident), *constructor, *(yystack_[1].value.methods));
	}
#line 616 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 6:
#line 165 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.ident) = (yystack_[0].value.ident);}
#line 622 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 7:
#line 166 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.ident) = new AST::Ident("Obj");}
#line 628 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 8:
#line 168 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.formals) = new AST::Formals();}
#line 634 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 9:
#line 169 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.formals) = (yystack_[1].value.formals); (yylhs.value.formals)->append((yystack_[0].value.formal)); }
#line 640 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 10:
#line 172 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.formal) = new AST::Formal(*(yystack_[2].value.ident), *(yystack_[0].value.ident)); }
#line 646 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 11:
#line 173 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.formal) = new AST::Formal(*(yystack_[2].value.ident), *(yystack_[0].value.ident)); }
#line 652 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 12:
#line 176 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.methods) = new AST::Methods(); }
#line 658 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 13:
#line 177 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.methods) = (yystack_[1].value.methods); (yylhs.value.methods)->append((yystack_[0].value.method)); }
#line 664 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 14:
#line 181 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.method) = new AST::Method(*(yystack_[5].value.ident), *(yystack_[3].value.formals), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 670 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 15:
#line 184 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.ident) = (yystack_[0].value.ident);}
#line 676 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 16:
#line 185 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.ident) = new AST::Ident("None"); }
#line 682 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 17:
#line 190 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.block) = (yystack_[1].value.block);
                                    (yylhs.value.block)->append((yystack_[0].value.statement));
                                  }
#line 690 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 18:
#line 193 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.block) = new AST::Block(); }
#line 696 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 19:
#line 199 "quack.yxx" // lalr1.cc:919
    {  (yylhs.value.block) = (yystack_[1].value.block); }
#line 702 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 20:
#line 216 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.statement) = new AST::While(*(yystack_[1].value.expr), *(yystack_[0].value.block)); }
#line 708 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 21:
#line 219 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.statement) = new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block)); }
#line 714 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 22:
#line 223 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.block) = new AST::Block();
               (yylhs.value.block)->append(new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block)));
             }
#line 722 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 23:
#line 227 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.block) = (yystack_[0].value.block); }
#line 728 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 24:
#line 229 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.block) = new AST::Block(); }
#line 734 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 25:
#line 241 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.statement) = new AST::Assign(*(yystack_[3].value.l_expr), *(yystack_[1].value.expr)); }
#line 740 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 26:
#line 245 "quack.yxx" // lalr1.cc:919
    {
      (yylhs.value.statement) = new AST::AssignDeclare(*(yystack_[5].value.l_expr), *(yystack_[1].value.expr), *(yystack_[3].value.ident));
    }
#line 748 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 27:
#line 250 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.statement) = new AST::Return(*(yystack_[1].value.expr)); }
#line 754 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 28:
#line 252 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.statement) = (yystack_[1].value.expr); }
#line 760 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 29:
#line 257 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.statement) = (yystack_[0].value.typecase); }
#line 766 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 30:
#line 260 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.typecase) = new AST::Typecase(*(yystack_[3].value.expr), *(yystack_[1].value.type_alternatives)); }
#line 772 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 31:
#line 262 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.type_alternatives) = new AST::Type_Alternatives(); }
#line 778 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 32:
#line 264 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.type_alternatives) = (yystack_[2].value.type_alternatives); (yylhs.value.type_alternatives)->append((yystack_[0].value.type_alternative)); }
#line 784 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 33:
#line 268 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.type_alternative) = new AST::Type_Alternative(*(yystack_[3].value.ident), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 790 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 34:
#line 278 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.l_expr) =  new AST::Ident((yystack_[0].value.str)); }
#line 796 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 35:
#line 279 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.l_expr) = new AST::Dot(*(yystack_[2].value.expr), *(yystack_[0].value.ident)); }
#line 802 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 36:
#line 290 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = (yystack_[1].value.expr); }
#line 808 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 37:
#line 297 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::Load(*(yystack_[0].value.l_expr)); }
#line 814 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 38:
#line 300 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::StrConst((yystack_[0].value.str)); }
#line 820 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 39:
#line 301 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::IntConst((yystack_[0].value.num)); }
#line 826 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 40:
#line 311 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = AST::Call::binop("TIMES", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 832 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 41:
#line 312 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = AST::Call::binop("PLUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 838 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 42:
#line 313 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = AST::Call::binop("MINUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 844 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 43:
#line 314 "quack.yxx" // lalr1.cc:919
    {
                              auto zero = new AST::IntConst(0);
                              (yylhs.value.expr) = AST::Call::binop("MINUS", *zero, *(yystack_[0].value.expr));
                            }
#line 853 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 44:
#line 319 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = AST::Call::binop("EQUALS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 859 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 45:
#line 320 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = AST::Call::binop("ATMOST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 865 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 46:
#line 321 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = AST::Call::binop("ATLEAST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 871 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 47:
#line 322 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = AST::Call::binop("LESS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 877 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 48:
#line 323 "quack.yxx" // lalr1.cc:919
    {(yylhs.value.expr) = AST::Call::binop("GREATER", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 883 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 49:
#line 325 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::And(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 889 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 50:
#line 326 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::Or(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 895 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 51:
#line 327 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::Not(*(yystack_[0].value.expr)); }
#line 901 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 52:
#line 347 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::Call(*(yystack_[5].value.expr), *(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 907 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 53:
#line 349 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.actuals) = new AST::Actuals(); }
#line 913 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 54:
#line 350 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.actuals) = (yystack_[0].value.actuals); }
#line 919 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 55:
#line 352 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.actuals) = (yystack_[2].value.actuals); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 925 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 56:
#line 353 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.actuals) = new AST::Actuals(); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 931 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 57:
#line 358 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.expr) = new AST::Construct(*(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 937 "quack.tab.cxx" // lalr1.cc:919
    break;

  case 58:
#line 361 "quack.yxx" // lalr1.cc:919
    { (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str)); }
#line 943 "quack.tab.cxx" // lalr1.cc:919
    break;


#line 947 "quack.tab.cxx" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -46;

  const signed char parser::yytable_ninf_ = -59;

  const short
  parser::yypact_[] =
  {
     -46,     6,    10,   -46,    -9,   -46,   210,   -46,     3,   102,
     102,   102,   102,   102,     5,   -46,   -46,   102,   102,   -46,
     -46,   -19,    33,    11,   -46,   -46,   228,   228,   136,   248,
      14,    22,   268,    -9,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,    -9,   -46,   102,    49,   -46,
      15,   -46,   -46,   -46,   -46,   -11,   173,   302,    50,    74,
      14,    14,    50,   302,   -20,   -20,    22,    30,   287,    13,
      17,    55,    -9,   -46,    44,     1,   102,    35,   -46,   -17,
     102,   -46,   102,   -46,   102,    -9,    51,    47,    -9,   -46,
     228,   -46,   -46,    -9,   190,    57,   287,   -46,   -46,    -9,
     -46,    15,   -46,    52,   -46,   -46,   210,   -46,   -46,    -9,
      -1,    35,    -9,   -46,   -46,   -46,    61,   -46,    58,    60,
      -9,    35,   -46,   -46
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,    18,     1,     0,     4,     2,    58,     0,     0,
       0,     0,     0,     0,    34,    39,    38,     0,     0,    17,
      29,    37,     0,     0,     8,    37,     0,     0,     0,     0,
      51,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    53,     0,    18,
      24,    20,    27,    31,    36,     0,     0,    46,    45,    44,
      49,    50,    48,    47,    41,    42,    40,    35,    56,     0,
      54,     7,     0,     9,     0,     0,     0,     0,    21,     0,
       0,    25,    53,    57,     0,     0,     0,     0,     0,    19,
       0,    23,    30,     0,     0,     0,    55,     6,    18,     0,
      10,    24,    32,     0,    26,    52,    12,    11,    22,     0,
       0,     0,     0,     5,    13,    33,     0,     8,     0,    16,
       0,     0,    15,    14
  };

  const signed char
  parser::yypgoto_[] =
  {
     -46,   -46,   -46,   -46,   -46,   -26,   -46,   -46,   -46,   -46,
     -45,   -25,   -46,    -7,   -46,   -46,   -46,    -5,   100,    18,
     -46,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,    86,    48,    73,   110,   114,   121,
       6,    50,    19,    78,    20,    79,   102,    25,    22,    69,
      70,    23
  };

  const signed char
  parser::yytable_[] =
  {
       8,    21,    51,   112,    75,    44,     3,     9,    45,     7,
      10,    11,    12,     4,    33,    92,    34,    93,    13,    14,
      15,    16,    76,    77,    80,    17,    35,    36,    37,    55,
      18,   113,    24,    89,   -58,    40,    41,    42,    43,    44,
      47,    67,    45,    83,    74,    35,    36,    37,    38,    39,
      45,    84,    91,   106,    40,    41,    42,    43,    44,    82,
      85,    45,    35,   -59,    37,   101,    49,     7,    87,    46,
      21,   -59,    41,    42,    43,    44,     7,    88,    45,    71,
      99,    97,    98,    72,   100,   109,   115,   105,   119,   103,
     117,   118,    72,   120,   108,   107,   123,    42,    43,    44,
      95,    21,    45,     0,     0,   111,     0,     0,   116,    26,
      27,    28,    29,    30,    74,     0,   122,    31,    32,    13,
      14,    15,    16,     0,     0,     0,    17,     0,     0,     0,
       0,    18,     0,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,    68,    35,    36,
      37,    38,    39,     0,     0,     0,     0,    40,    41,    42,
      43,    44,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    90,     0,     0,     0,
      94,     0,    68,     0,    96,    35,    36,    37,    38,    39,
       0,     0,     0,     0,    40,    41,    42,    43,    44,     0,
       0,    45,    35,    36,    37,    38,    39,     0,     0,    81,
       0,    40,    41,    42,    43,    44,     9,     0,    45,    10,
      11,    12,     0,     0,     0,     0,   104,    13,    14,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      35,    36,    37,    38,    39,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,    45,     0,     0,    49,
      35,    36,    37,    38,    39,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,    45,     0,     0,    53,
      35,    36,    37,    38,    39,     0,     0,     0,     0,    40,
      41,    42,    43,    44,     0,     0,    45,     0,    54,    35,
      36,    37,    38,    39,     0,     0,     0,     0,    40,    41,
      42,    43,    44,     0,   -59,    45,    37,     0,     0,     0,
       0,     0,     0,     0,   -59,    42,    43,    44,     0,     0,
      45
  };

  const signed char
  parser::yycheck_[] =
  {
       4,     6,    27,     4,    49,    25,     0,     6,    28,    18,
       9,    10,    11,     3,    33,    32,    35,    34,    17,    18,
      19,    20,     7,     8,    35,    24,    12,    13,    14,    33,
      29,    32,    29,    32,    29,    21,    22,    23,    24,    25,
      29,    45,    28,    30,    48,    12,    13,    14,    15,    16,
      28,    34,    77,    98,    21,    22,    23,    24,    25,    29,
       5,    28,    12,    13,    14,    90,    31,    18,    72,    36,
      75,    21,    22,    23,    24,    25,    18,    33,    28,    30,
      33,    85,    31,    34,    88,    33,   111,    30,    30,    93,
      29,   117,    34,    33,   101,    99,   121,    23,    24,    25,
      82,   106,    28,    -1,    -1,   109,    -1,    -1,   112,     9,
      10,    11,    12,    13,   118,    -1,   120,    17,    18,    17,
      18,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    84,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    28,    12,    13,    14,    15,    16,    -1,    -1,    36,
      -1,    21,    22,    23,    24,    25,     6,    -1,    28,     9,
      10,    11,    -1,    -1,    -1,    -1,    36,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,    31,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    -1,    -1,    31,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    28,    -1,    30,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    12,    28,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    38,    39,     0,     3,    40,    47,    18,    58,     6,
       9,    10,    11,    17,    18,    19,    20,    24,    29,    49,
      51,    54,    55,    58,    29,    54,    55,    55,    55,    55,
      55,    55,    55,    33,    35,    12,    13,    14,    15,    16,
      21,    22,    23,    24,    25,    28,    36,    29,    42,    31,
      48,    48,    36,    31,    30,    58,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    58,    55,    56,
      57,    30,    34,    43,    58,    47,     7,     8,    50,    52,
      35,    36,    29,    30,    34,     5,    41,    58,    33,    32,
      55,    48,    32,    34,    55,    56,    55,    58,    31,    33,
      58,    48,    53,    58,    36,    30,    47,    58,    50,    33,
      44,    58,     4,    32,    45,    48,    58,    29,    42,    30,
      33,    46,    58,    48
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    50,    50,    49,    49,    49,    49,    49,
      51,    52,    52,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    55,    58
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,    10,     2,     0,     0,     2,
       3,     4,     0,     2,     7,     2,     0,     2,     0,     3,
       3,     4,     4,     2,     0,     4,     6,     3,     2,     1,
       5,     0,     3,     4,     1,     3,     3,     1,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     2,     6,     0,     1,     3,     1,     4,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "RETURN", "TYPECASE", "ATLEAST", "ATMOST", "EQUALS",
  "AND", "OR", "NOT", "IDENT", "INT_LIT", "STRING_LIT", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "NEG", "'.'", "'('", "')'", "'{'", "'}'",
  "':'", "','", "'='", "';'", "$accept", "pgm", "classes", "class",
  "opt_extends", "formals", "formal", "methods", "method", "return_type",
  "statements", "statement_block", "statement", "opt_elif_parts",
  "typecase", "type_alternatives", "type_alternative", "l_expr", "expr",
  "actual_args", "actual_args_nonempty", "ident", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   143,   143,   154,   155,   158,   165,   166,   168,   169,
     172,   173,   176,   177,   180,   184,   185,   190,   193,   198,
     215,   218,   222,   226,   229,   240,   244,   250,   252,   257,
     259,   262,   263,   267,   278,   279,   290,   297,   300,   301,
     311,   312,   313,   314,   319,   320,   321,   322,   323,   325,
     326,   327,   346,   349,   350,   352,   353,   357,   361
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,    25,    23,    34,    24,    28,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    36,
      22,    35,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    27
    };
    const unsigned user_token_number_max_ = 276;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1411 "quack.tab.cxx" // lalr1.cc:1242
#line 363 "quack.yxx" // lalr1.cc:1243


void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}
