// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.hpp"


// Unqualified %code blocks.
#line 48 "parser.yy"


    #include <iostream>

    #include "headers/Lexer.hpp"

    #include "headers/TAC.hpp"

    #include <stack>

    using namespace std;

    #define yylex lexer->lex

    // ========================================================
    // ESTRUCTURAS GLOBALES
    // ========================================================

    TypeTab tablaTipos;

    PilaTs pilaTs;

    stack<int> pilaDir;

    int dir = 0;

    int currentType = -1;

    vector<int> listaParams;

    int tipoReturn = -1;

    stack<string> pilaBreak;

    bool funcionValida = true;

    int tipoStructActual;

    // ========================================================
    // FUNCIONES AUXILIARES DE TIPOS
    // ========================================================

    bool esNumerico(int tipo){

        return tipo == tablaTipos.getId("int") ||
            tipo == tablaTipos.getId("float");
    }

    bool esBooleano(int tipo){

        return tipo == tablaTipos.getId("bool");
    }

    bool tiposCompatibles(int t1, int t2){

        if(t1 == t2)
            return true;

        // int -> float permitido
        if(t1 == tablaTipos.getId("float") &&
            t2 == tablaTipos.getId("int"))
            return true;

        return false;
    }

    int tipoDominante(int t1, int t2){

        if(t1 == tablaTipos.getId("float") ||
            t2 == tablaTipos.getId("float"))
                return tablaTipos.getId("float");

        return tablaTipos.getId("int");
    }


#line 123 "Parser.cpp"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 13 "parser.yy"
namespace C1 {
#line 197 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer* lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.copy< Attr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.copy< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.move< Attr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< char* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.YY_MOVE_OR_COPY< Attr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.YY_MOVE_OR_COPY< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.move< Attr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
        value.move< char* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.copy< Attr > (that.value);
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.copy< char* > (that.value);
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        value.move< Attr > (that.value);
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        value.move< char > (that.value);
        break;

      case symbol_kind::S_ID: // ID
        value.move< char* > (that.value);
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        value.move< float > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_P: // P
      case symbol_kind::S_STRUCT_VARS: // STRUCT_VARS
      case symbol_kind::S_D: // D
      case symbol_kind::S_FUNC: // FUNC
      case symbol_kind::S_T: // T
      case symbol_kind::S_B: // B
      case symbol_kind::S_A: // A
      case symbol_kind::S_L: // L
      case symbol_kind::S_F: // F
      case symbol_kind::S_BLOQUE: // BLOQUE
      case symbol_kind::S_S: // S
      case symbol_kind::S_LVALUE: // LVALUE
      case symbol_kind::S_STMT: // STMT
      case symbol_kind::S_RETURN_STMT: // RETURN_STMT
      case symbol_kind::S_E: // E
      case symbol_kind::S_ARGS: // ARGS
        yylhs.value.emplace< Attr > ();
        break;

      case symbol_kind::S_CHAR_LITERAL: // CHAR_LITERAL
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_ID: // ID
        yylhs.value.emplace< char* > ();
        break;

      case symbol_kind::S_FLOAT_LITERAL: // FLOAT_LITERAL
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< int > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 269 "parser.yy"
    {
        dir = 0;

        pilaTs.push(new SymTab());
    }
#line 921 "Parser.cpp"
    break;

  case 3: // P: $@1 D
#line 277 "parser.yy"
    {
        cout << endl;

        tablaTipos.print();

        cout << endl;

        cout << "TABLA GLOBAL" << endl;

        pilaTs.top()->print();
    }
#line 937 "Parser.cpp"
    break;

  case 4: // STRUCT_VARS: ID
#line 297 "parser.yy"
    {
        // currentType was set in your mid-rule action in D!
        if (currentType != -1) {
            pilaTs.top()->addSym(yystack_[0].value.as < char* > (), dir, currentType, "var");
            dir += tablaTipos.getTam(currentType);
        }
        free(yystack_[0].value.as < char* > ());
    }
#line 950 "Parser.cpp"
    break;

  case 5: // STRUCT_VARS: STRUCT_VARS COMMA ID
#line 306 "parser.yy"
    {
        if (currentType != -1) {
            pilaTs.top()->addSym(yystack_[0].value.as < char* > (), dir, currentType, "var");
            dir += tablaTipos.getTam(currentType);
        }
        free(yystack_[0].value.as < char* > ());
    }
#line 962 "Parser.cpp"
    break;

  case 6: // STRUCT_VARS: %empty
#line 314 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 970 "Parser.cpp"
    break;

  case 7: // D: FUNC D
#line 321 "parser.yy"
    { yylhs.value.as < Attr > () = yystack_[1].value.as < Attr > (); }
#line 976 "Parser.cpp"
    break;

  case 8: // D: T L SEMICOLON D
#line 325 "parser.yy"
    { yylhs.value.as < Attr > () = yystack_[3].value.as < Attr > (); }
#line 982 "Parser.cpp"
    break;

  case 9: // $@2: %empty
#line 330 "parser.yy"
    {
        pilaTs.push(new SymTab());

        pilaDir.push(dir);

        dir = 0;
    }
#line 994 "Parser.cpp"
    break;

  case 10: // $@3: %empty
#line 339 "parser.yy"
    {
        // Mid-rule action — runs BEFORE L
        SymTab* ts = pilaTs.pop();
        int tamStruct = dir;
        dir = pilaDir.top();
        pilaDir.pop();

        string nombreStruct = yystack_[4].value.as < char* > ();

        if(tablaTipos.getId(nombreStruct) != -1){
            cerr << "Struct redeclarado: " << nombreStruct << endl;
            currentType = -1;
        }
        else{
            int tipoStruct = tablaTipos.addStructType(
                nombreStruct,
                tamStruct,
                ts
            );
            currentType = tipoStruct; 
        }
    }
#line 1021 "Parser.cpp"
    break;

  case 11: // D: STRUCT ID $@2 LBRACE D RBRACE $@3 STRUCT_VARS SEMICOLON D
#line 363 "parser.yy"
    {
        if(yystack_[8].value.as < char* > ()) free(yystack_[8].value.as < char* > ());
    }
#line 1029 "Parser.cpp"
    break;

  case 12: // D: %empty
#line 371 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 1037 "Parser.cpp"
    break;

  case 13: // $@4: %empty
#line 385 "parser.yy"
    {
        string id = yystack_[0].value.as < char* > ();

        if(pilaTs.bottom()->existe(id)){

            cerr << "Función redeclarada: "
                 << id
                 << endl;
        }
        else{

            // Nuevo scope para función
            pilaTs.push(new SymTab());

            // Guardar dir actual
            pilaDir.push(dir);

            // Reiniciar offset local
            dir = 0;

            // Guardar tipo retorno
            tipoReturn = yystack_[1].value.as < Attr > ().tipo;
        }
    }
#line 1066 "Parser.cpp"
    break;

  case 14: // FUNC: DEF T ID $@4 LPAREN F RPAREN BLOQUE
#line 414 "parser.yy"
    {
        string id = yystack_[5].value.as < char* > ();

        for(string instr : yystack_[0].value.as < Attr > ().code){
            codigo.push_back(instr);
        }

        SymTab* tsFunc = pilaTs.top();

        cout << "\nTABLA FUNCION " << id << endl;
        tsFunc->print();

        pilaTs.pop();

        dir = pilaDir.top();
        pilaDir.pop();

        // Registrar función global
        pilaTs.bottom()->addSym(
            id,
            -1,
            yystack_[6].value.as < Attr > ().tipo,
            "func",
            listaParams
        );

        listaParams.clear();

        free(yystack_[5].value.as < char* > ());
    }
#line 1101 "Parser.cpp"
    break;

  case 15: // $@5: %empty
#line 455 "parser.yy"
    {
        currentType = yystack_[0].value.as < Attr > ().tipo;
    }
#line 1109 "Parser.cpp"
    break;

  case 16: // T: B $@5 A
#line 461 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = yystack_[0].value.as < Attr > ().tipo;
        currentType = yylhs.value.as < Attr > ().tipo;
    }
#line 1118 "Parser.cpp"
    break;

  case 17: // $@6: %empty
#line 470 "parser.yy"
    {
        pilaTs.push(new SymTab());

        pilaDir.push(dir);

        dir = 0;
    }
#line 1130 "Parser.cpp"
    break;

  case 18: // T: REGISTER LBRACE $@6 D RBRACE
#line 480 "parser.yy"
    {
        SymTab* tsStruct =
            pilaTs.pop();

        int tamStruct = dir;

        dir = pilaDir.top();

        pilaDir.pop();

        string nombreStruct =
            "struct_" +
            to_string(tablaTipos.getTam(0))
            + "_"
            + to_string(rand());

        int tipoStruct =
            tablaTipos.addStructType(
                nombreStruct,
                tamStruct,
                tsStruct
            );

        yylhs.value.as < Attr > ().tipo = tipoStruct;

        currentType = tipoStruct;
    }
#line 1162 "Parser.cpp"
    break;

  case 19: // B: INT
#line 517 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
    }
#line 1170 "Parser.cpp"
    break;

  case 20: // B: FLOAT
#line 524 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = tablaTipos.getId("float");
    }
#line 1178 "Parser.cpp"
    break;

  case 21: // B: BOOL
#line 531 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = tablaTipos.getId("bool");
    }
#line 1186 "Parser.cpp"
    break;

  case 22: // B: CHAR
#line 538 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = tablaTipos.getId("char");
    }
#line 1194 "Parser.cpp"
    break;

  case 23: // A: LBRACKET NUM RBRACKET A
#line 552 "parser.yy"
    {
        if(yystack_[2].value.as < int > () <= 0){

            cerr << "Error: tamaño inválido de arreglo"
                 << endl;
        }

        yylhs.value.as < Attr > ().tipo =
            tablaTipos.addArrayType(yystack_[2].value.as < int > (),
                                    yystack_[0].value.as < Attr > ().tipo);
    }
#line 1210 "Parser.cpp"
    break;

  case 24: // A: %empty
#line 567 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo = currentType;
    }
#line 1218 "Parser.cpp"
    break;

  case 25: // L: L COMMA ID
#line 581 "parser.yy"
    {
        string id = yystack_[0].value.as < char* > ();

        if(!pilaTs.lookup(id)){

            pilaTs.top()->addSym(id,
                                 dir,
                                 currentType,
                                 "var");

            dir += tablaTipos.getTam(currentType);
        }
        else{

            cerr << "Variable redeclarada: "
                 << id
                 << endl;
        }

        free(yystack_[0].value.as < char* > ());
    }
#line 1244 "Parser.cpp"
    break;

  case 26: // L: ID
#line 607 "parser.yy"
    {
        string id = yystack_[0].value.as < char* > ();

        if(!pilaTs.lookup(id)){

            pilaTs.top()->addSym(id,
                                 dir,
                                 currentType,
                                 "var");

            dir += tablaTipos.getTam(currentType);
        }
        else{

            cerr << "Variable redeclarada: "
                 << id
                 << endl;
        }

        free(yystack_[0].value.as < char* > ());
    }
#line 1270 "Parser.cpp"
    break;

  case 27: // F: F COMMA T ID
#line 636 "parser.yy"
    {
        pilaTs.top()->addSym(yystack_[0].value.as < char* > (), dir, yystack_[1].value.as < Attr > ().tipo, "param");
        dir += tablaTipos.getTam(yystack_[1].value.as < Attr > ().tipo);
        listaParams.push_back(yystack_[1].value.as < Attr > ().tipo);
        free(yystack_[0].value.as < char* > ());
    }
#line 1281 "Parser.cpp"
    break;

  case 28: // F: T ID
#line 643 "parser.yy"
    {
        pilaTs.top()->addSym(yystack_[0].value.as < char* > (), dir, yystack_[1].value.as < Attr > ().tipo, "param");
        dir += tablaTipos.getTam(yystack_[1].value.as < Attr > ().tipo);
        listaParams.push_back(yystack_[1].value.as < Attr > ().tipo);
        free(yystack_[0].value.as < char* > ());
    }
#line 1292 "Parser.cpp"
    break;

  case 29: // F: %empty
#line 649 "parser.yy"
                  { yylhs.value.as < Attr > () = Attr(); }
#line 1298 "Parser.cpp"
    break;

  case 30: // BLOQUE: LBRACE S RBRACE
#line 659 "parser.yy"
    {
        yylhs.value.as < Attr > () = yystack_[1].value.as < Attr > ();
    }
#line 1306 "Parser.cpp"
    break;

  case 31: // S: STMT S
#line 672 "parser.yy"
    {
        yylhs.value.as < Attr > ().code = yystack_[1].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );
    }
#line 1320 "Parser.cpp"
    break;

  case 32: // S: %empty
#line 685 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 1328 "Parser.cpp"
    break;

  case 33: // LVALUE: ID
#line 692 "parser.yy"
    {
        string id = yystack_[0].value.as < char* > ();
        
        if (!pilaTs.lookup(id)) {
            cerr << "Variable no declarada: " << id << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
            yylhs.value.as < Attr > ().dir  = id;
        } else {
            yylhs.value.as < Attr > ().tipo = pilaTs.lookupType(id);
            yylhs.value.as < Attr > ().dir  = id;          // use name as address in TAC
        }
        yylhs.value.as < Attr > ().code = {};
        
        free(yystack_[0].value.as < char* > ());
    }
#line 1348 "Parser.cpp"
    break;

  case 34: // LVALUE: LVALUE LBRACKET E RBRACKET
#line 709 "parser.yy"
    {
        int baseType = tablaTipos.getTipoBase(yystack_[3].value.as < Attr > ().tipo);
        if (baseType == -1) {
            cerr << "Subíndice sobre tipo no arreglo" << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
            yylhs.value.as < Attr > ().dir  = yystack_[3].value.as < Attr > ().dir;
            yylhs.value.as < Attr > ().ldir = yystack_[3].value.as < Attr > ().dir;
        } else {
            if (!esNumerico(yystack_[1].value.as < Attr > ().tipo)) {
                cerr << "Índice de arreglo no entero" << endl;
            }

            int tamBase = tablaTipos.getTam(baseType);

            string tOffset = nuevaTemp();
            string tVal    = nuevaTemp();

            yylhs.value.as < Attr > ().code = yystack_[3].value.as < Attr > ().code;
            yylhs.value.as < Attr > ().code.insert(yylhs.value.as < Attr > ().code.end(), yystack_[1].value.as < Attr > ().code.begin(), yystack_[1].value.as < Attr > ().code.end());

            yylhs.value.as < Attr > ().code.push_back(
                tOffset + " = " + yystack_[1].value.as < Attr > ().dir + " * " + to_string(tamBase)
            );

            // ldir = the addressable form (used when this is an assignment target)
            yylhs.value.as < Attr > ().ldir = yystack_[3].value.as < Attr > ().dir + "[" + tOffset + "]";

            // dir = a temp holding the loaded value (used when this is an rvalue)
            yylhs.value.as < Attr > ().code.push_back(tVal + " = " + yylhs.value.as < Attr > ().ldir);
            yylhs.value.as < Attr > ().dir  = tVal;
            yylhs.value.as < Attr > ().tipo = baseType;
        }
    }
#line 1386 "Parser.cpp"
    break;

  case 35: // LVALUE: LVALUE DOT ID
#line 744 "parser.yy"
    {
        string campo = yystack_[0].value.as < char* > ();
        SymTab* tsStruct = tablaTipos.getTS(yystack_[2].value.as < Attr > ().tipo);

        if (tsStruct == nullptr) {
            cerr << "Acceso con '.' sobre tipo no struct" << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
            yylhs.value.as < Attr > ().dir  = yystack_[2].value.as < Attr > ().dir;
            yylhs.value.as < Attr > ().ldir = yystack_[2].value.as < Attr > ().dir;
        } else if (!tsStruct->existe(campo)) {
            cerr << "Campo inexistente: " << campo << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
            yylhs.value.as < Attr > ().dir  = yystack_[2].value.as < Attr > ().dir;
            yylhs.value.as < Attr > ().ldir = yystack_[2].value.as < Attr > ().dir;
        } else {
            yylhs.value.as < Attr > ().tipo = tsStruct->getType(campo);
            yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

            // ldir = the addressable form (used when this is an assignment target)
            yylhs.value.as < Attr > ().ldir = yystack_[2].value.as < Attr > ().dir + "." + campo;

            // dir = a temp holding the loaded value (used when this is an rvalue)
            string t = nuevaTemp();
            yylhs.value.as < Attr > ().code.push_back(t + " = " + yylhs.value.as < Attr > ().ldir);
            yylhs.value.as < Attr > ().dir = t;
        }

        free(yystack_[0].value.as < char* > ());
    }
#line 1420 "Parser.cpp"
    break;

  case 36: // STMT: LVALUE ASSIGN E SEMICOLON
#line 778 "parser.yy"
    {
        if (!tiposCompatibles(yystack_[3].value.as < Attr > ().tipo, yystack_[1].value.as < Attr > ().tipo)) {
            cerr << "Tipos incompatibles en asignación" << endl;
        }

        yylhs.value.as < Attr > ().code = yystack_[3].value.as < Attr > ().code;
        yylhs.value.as < Attr > ().code.insert(yylhs.value.as < Attr > ().code.end(), yystack_[1].value.as < Attr > ().code.begin(), yystack_[1].value.as < Attr > ().code.end());

        string dest = yystack_[3].value.as < Attr > ().ldir.empty() ? yystack_[3].value.as < Attr > ().dir : yystack_[3].value.as < Attr > ().ldir;
        yylhs.value.as < Attr > ().code.push_back(dest + " = " + yystack_[1].value.as < Attr > ().dir);
        
    }
#line 1437 "Parser.cpp"
    break;

  case 37: // STMT: IF LPAREN E RPAREN STMT
#line 796 "parser.yy"
    {
        if(!esBooleano(yystack_[2].value.as < Attr > ().tipo)){

            cerr 
                << "Condición no booleana en if"
                << endl;
        }

        string Lfin = nuevaLabel();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.push_back(
            "ifFalse "
            + yystack_[2].value.as < Attr > ().dir
            + " goto "
            + Lfin
        );

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            Lfin + ":"
        );
    }
#line 1471 "Parser.cpp"
    break;

  case 38: // STMT: IF LPAREN E RPAREN STMT ELSE STMT
#line 831 "parser.yy"
    {
        if(!esBooleano(yystack_[4].value.as < Attr > ().tipo)){

            cerr 
                << "Condición no booleana en if"
                << endl;
        }

        string Lelse = nuevaLabel();
        string Lfin  = nuevaLabel();

        yylhs.value.as < Attr > ().code = yystack_[4].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.push_back(
            "ifFalse "
            + yystack_[4].value.as < Attr > ().dir
            + " goto "
            + Lelse
        );

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[2].value.as < Attr > ().code.begin(),
            yystack_[2].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            "goto " + Lfin
        );

        yylhs.value.as < Attr > ().code.push_back(
            Lelse + ":"
        );

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            Lfin + ":"
        );
    }
#line 1520 "Parser.cpp"
    break;

  case 39: // STMT: WHILE LPAREN E RPAREN STMT
#line 880 "parser.yy"
    {
        if(!esBooleano(yystack_[2].value.as < Attr > ().tipo)){

            cerr << "Condición no booleana en while"
                 << endl;
        }

        string Linicio = nuevaLabel();
        string Lfin    = nuevaLabel();

        yylhs.value.as < Attr > ().code.push_back(
            Linicio + ":"
        );

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[2].value.as < Attr > ().code.begin(),
            yystack_[2].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            "ifFalse "
            + yystack_[2].value.as < Attr > ().dir
            + " goto "
            + Lfin
        );

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            "goto " + Linicio
        );

        yylhs.value.as < Attr > ().code.push_back(
            Lfin + ":"
        );
    }
#line 1566 "Parser.cpp"
    break;

  case 40: // STMT: FOR LPAREN ID ASSIGN E SEMICOLON E SEMICOLON ID ASSIGN E RPAREN STMT
#line 931 "parser.yy"
    {
        string Linicio = nuevaLabel();
        string Lfin    = nuevaLabel();

        // Inicialización

        yylhs.value.as < Attr > ().code = yystack_[8].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.push_back(
            string(yystack_[10].value.as < char* > ())
            + " = "
            + yystack_[8].value.as < Attr > ().dir
        );

        // Inicio del ciclo

        yylhs.value.as < Attr > ().code.push_back(
            Linicio + ":"
        );

        // Condición

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[6].value.as < Attr > ().code.begin(),
            yystack_[6].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            "ifFalse "
            + yystack_[6].value.as < Attr > ().dir
            + " goto "
            + Lfin
        );

        // Cuerpo

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        // Incremento

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[2].value.as < Attr > ().code.begin(),
            yystack_[2].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            string(yystack_[4].value.as < char* > ())
            + " = "
            + yystack_[2].value.as < Attr > ().dir
        );

        // Regreso

        yylhs.value.as < Attr > ().code.push_back(
            "goto " + Linicio
        );

        yylhs.value.as < Attr > ().code.push_back(
            Lfin + ":"
        );

        free(yystack_[10].value.as < char* > ());
        free(yystack_[4].value.as < char* > ());
    }
#line 1641 "Parser.cpp"
    break;

  case 41: // STMT: BREAK SEMICOLON
#line 1005 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 1649 "Parser.cpp"
    break;

  case 42: // STMT: RETURN_STMT
#line 1013 "parser.yy"
    {
        yylhs.value.as < Attr > () = yystack_[0].value.as < Attr > ();
    }
#line 1657 "Parser.cpp"
    break;

  case 43: // STMT: BLOQUE
#line 1019 "parser.yy"
    { yylhs.value.as < Attr > () = yystack_[0].value.as < Attr > (); }
#line 1663 "Parser.cpp"
    break;

  case 44: // STMT: T L SEMICOLON
#line 1025 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 1671 "Parser.cpp"
    break;

  case 45: // RETURN_STMT: RETURN E SEMICOLON
#line 1039 "parser.yy"
    {
        if(!tiposCompatibles(tipoReturn,
                            yystack_[1].value.as < Attr > ().tipo)){
            cerr 
                << "Tipo de retorno incorrecto"
                << endl;
        }
        yylhs.value.as < Attr > ().tipo = yystack_[1].value.as < Attr > ().tipo;
        yylhs.value.as < Attr > ().dir = yystack_[1].value.as < Attr > ().dir;
        yylhs.value.as < Attr > ().code = yystack_[1].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.push_back(
            "return "
            + yystack_[1].value.as < Attr > ().dir
        );
    }
#line 1692 "Parser.cpp"
    break;

  case 46: // E: E PLUS E
#line 1066 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
        !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Error: suma inválida"
            << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
    }
    else{
        yylhs.value.as < Attr > ().tipo =
            tipoDominante(yystack_[2].value.as < Attr > ().tipo,
                           yystack_[0].value.as < Attr > ().tipo);
        }

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " + " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1728 "Parser.cpp"
    break;

  case 47: // E: E MINUS E
#line 1102 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Error: resta inválida"
            << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
        }
        else{
            yylhs.value.as < Attr > ().tipo =
                tipoDominante(yystack_[2].value.as < Attr > ().tipo,
                               yystack_[0].value.as < Attr > ().tipo);
        }

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " - " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1764 "Parser.cpp"
    break;

  case 48: // E: E MULT E
#line 1138 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Error: multiplicación inválida"
                 << endl;

            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
        }
        else{
            yylhs.value.as < Attr > ().tipo =
                tipoDominante(yystack_[2].value.as < Attr > ().tipo,
                               yystack_[0].value.as < Attr > ().tipo);
        }

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " * " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1801 "Parser.cpp"
    break;

  case 49: // E: E DIV E
#line 1175 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Error: división inválida"
                 << endl;
            yylhs.value.as < Attr > ().tipo = tablaTipos.getId("int");
        }
        else{
            yylhs.value.as < Attr > ().tipo =
                tipoDominante(yystack_[2].value.as < Attr > ().tipo,
                               yystack_[0].value.as < Attr > ().tipo);
        }

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " / " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1837 "Parser.cpp"
    break;

  case 50: // E: E LT E
#line 1211 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " < " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1869 "Parser.cpp"
    break;

  case 51: // E: E LE E
#line 1243 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " <= " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1901 "Parser.cpp"
    break;

  case 52: // E: E GT E
#line 1275 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " > " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1933 "Parser.cpp"
    break;

  case 53: // E: E GE E
#line 1307 "parser.yy"
    {
        if(!esNumerico(yystack_[2].value.as < Attr > ().tipo) ||
           !esNumerico(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " >= " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1965 "Parser.cpp"
    break;

  case 54: // E: E EQ E
#line 1339 "parser.yy"
    {
        if(!tiposCompatibles(yystack_[2].value.as < Attr > ().tipo,
                             yystack_[0].value.as < Attr > ().tipo) &&
           !tiposCompatibles(yystack_[0].value.as < Attr > ().tipo,
                             yystack_[2].value.as < Attr > ().tipo)){
            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " == " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 1999 "Parser.cpp"
    break;

  case 55: // E: E NEQ E
#line 1373 "parser.yy"
    {
        if(!tiposCompatibles(yystack_[2].value.as < Attr > ().tipo,
                             yystack_[0].value.as < Attr > ().tipo) &&
           !tiposCompatibles(yystack_[0].value.as < Attr > ().tipo,
                             yystack_[2].value.as < Attr > ().tipo)){

            cerr << "Comparación inválida"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " != " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 2034 "Parser.cpp"
    break;

  case 56: // E: E AND E
#line 1408 "parser.yy"
    {
        if(!esBooleano(yystack_[2].value.as < Attr > ().tipo) ||
           !esBooleano(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "AND requiere booleanos"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " && " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 2066 "Parser.cpp"
    break;

  case 57: // E: E OR E
#line 1440 "parser.yy"
    {
        if(!esBooleano(yystack_[2].value.as < Attr > ().tipo) ||
           !esBooleano(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "OR requiere booleanos"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );

        yylhs.value.as < Attr > ().code.push_back(
            t + " = " +
            yystack_[2].value.as < Attr > ().dir + " || " +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 2098 "Parser.cpp"
    break;

  case 58: // E: NOT E
#line 1472 "parser.yy"
    {
        if(!esBooleano(yystack_[0].value.as < Attr > ().tipo)){
            cerr << "NOT requiere booleano"
                 << endl;
        }
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");

        string t = nuevaTemp();

        yylhs.value.as < Attr > ().code = yystack_[0].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.push_back(
            t + " = !" +
            yystack_[0].value.as < Attr > ().dir
        );

        yylhs.value.as < Attr > ().dir = t;
    }
#line 2122 "Parser.cpp"
    break;

  case 59: // E: E DOT ID
#line 1496 "parser.yy"
    {
        // ====================================================
        // Verificar que E sea struct
        // ====================================================

        SymTab* tsStruct =
            tablaTipos.getTS(yystack_[2].value.as < Attr > ().tipo);

        if(tsStruct == nullptr){

            cerr
                << "Acceso con '.' sobre tipo no struct"
                << endl;

            yylhs.value.as < Attr > ().tipo =
                tablaTipos.getId("int");
        }

        else{

            string campo = yystack_[0].value.as < char* > ();

            // ====================================================
            // Verificar campo
            // ====================================================

            if(!tsStruct->existe(campo)){

                cerr
                    << "Campo inexistente: "
                    << campo
                    << endl;

                yylhs.value.as < Attr > ().tipo =
                    tablaTipos.getId("int");
            }

            else{
                
                yylhs.value.as < Attr > ().tipo =
                    tsStruct->getType(campo);

                //int offset =
                    // tsStruct->getDir(campo);

                // ====================================================
                // TAC
                // ====================================================

                string t = nuevaTemp();

                yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

                yylhs.value.as < Attr > ().code.push_back(
                    t
                    + " = "
                    + yystack_[2].value.as < Attr > ().dir
                    + "."
                    + campo
                );

                yylhs.value.as < Attr > ().dir = t;
            }

            free(yystack_[0].value.as < char* > ());
        }
    }
#line 2194 "Parser.cpp"
    break;

  case 60: // E: LPAREN E RPAREN
#line 1568 "parser.yy"
    {
        yylhs.value.as < Attr > ().code = yystack_[1].value.as < Attr > ().code;
        yylhs.value.as < Attr > ().tipo = yystack_[1].value.as < Attr > ().tipo;
        yylhs.value.as < Attr > ().dir = yystack_[1].value.as < Attr > ().dir;
    }
#line 2204 "Parser.cpp"
    break;

  case 61: // E: NUM
#line 1579 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("int");

        yylhs.value.as < Attr > ().dir =
            to_string(yystack_[0].value.as < int > ());
    }
#line 2216 "Parser.cpp"
    break;

  case 62: // E: FLOAT_LITERAL
#line 1591 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("float");
        
        yylhs.value.as < Attr > ().dir =
            to_string(yystack_[0].value.as < float > ());
    }
#line 2228 "Parser.cpp"
    break;

  case 63: // E: CHAR_LITERAL
#line 1603 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("char");
        yylhs.value.as < Attr > ().dir = string("'") + yystack_[0].value.as < char > () + "'";
    }
#line 2238 "Parser.cpp"
    break;

  case 64: // E: TRUE
#line 1613 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");
        yylhs.value.as < Attr > ().dir = "true";
    }
#line 2248 "Parser.cpp"
    break;

  case 65: // E: FALSE
#line 1623 "parser.yy"
    {
        yylhs.value.as < Attr > ().tipo =
            tablaTipos.getId("bool");
        yylhs.value.as < Attr > ().dir = "false";
    }
#line 2258 "Parser.cpp"
    break;

  case 66: // E: LVALUE
#line 1630 "parser.yy"
    {
        yylhs.value.as < Attr > ().dir = yystack_[0].value.as < Attr > ().dir;
        yylhs.value.as < Attr > ().tipo = yystack_[0].value.as < Attr > ().tipo;
        yylhs.value.as < Attr > ().code = yystack_[0].value.as < Attr > ().code;
        // $$.dir = nuevaTemporal();
        // genCode($$.dir + " = " + $1.base + "[" + $1.dir + "]");
        // $$.tipo = $1.tipo;
    }
#line 2271 "Parser.cpp"
    break;

  case 67: // E: ID LPAREN ARGS RPAREN
#line 1643 "parser.yy"
    {
        string id = yystack_[3].value.as < char* > ();

        // ====================================================
        // Verificar existencia
        // ====================================================

        if(!pilaTs.bottom()->existe(id)){

            cerr
                << "Funcion no declarada: "
                << id
                << endl;

            yylhs.value.as < Attr > ().tipo =
                tablaTipos.getId("int");
        }

        else{

            // ====================================================
            // Verificar categoría
            // ====================================================

            if(pilaTs.bottom()->getCat(id) != "func"){

                cerr
                    << id
                    << " no es una funcion"
                    << endl;
            }

            // ====================================================
            // Obtener parámetros esperados
            // ====================================================

            vector<int> esperados =
                pilaTs.bottom()->getParams(id);

            // ====================================================
            // Verificar cantidad de argumentos
            // ====================================================

            if(esperados.size() != yystack_[1].value.as < Attr > ().lista.size()){

                cerr
                    << "Cantidad incorrecta de argumentos en llamada a "
                    << id
                    << endl;
            }

            // ====================================================
            // Verificar tipos de argumentos
            // ====================================================

            else{

                for(size_t i = 0;
                    i < esperados.size();
                    i++){

                    if(!tiposCompatibles(
                            esperados[i],
                            yystack_[1].value.as < Attr > ().lista[i])){

                        cerr
                            << "Tipo incompatible en argumento "
                            << i + 1
                            << " de llamada a "
                            << id
                            << endl;
                    }
                }
            }

            // ====================================================
            // Generar PARAMS TAC
            // ====================================================

            yylhs.value.as < Attr > ().code = yystack_[1].value.as < Attr > ().code;
            for(string d : yystack_[1].value.as < Attr > ().listaDir){

                yylhs.value.as < Attr > ().code.push_back(
                    "param " + d
                );

            }

            // ====================================================
            // Generar CALL TAC
            // ====================================================

            string t = nuevaTemp();

            yylhs.value.as < Attr > ().code.push_back(
                t
                + " = call "
                + id
                + ", "
                + to_string(yystack_[1].value.as < Attr > ().listaDir.size())
            );


            // ====================================================
            // Resultado
            // ====================================================

            yylhs.value.as < Attr > ().dir = t;

            yylhs.value.as < Attr > ().tipo =
                pilaTs.bottom()->getType(id);
        }

        free(yystack_[3].value.as < char* > ());
    }
#line 2391 "Parser.cpp"
    break;

  case 68: // ARGS: E
#line 1769 "parser.yy"
    {
        yylhs.value.as < Attr > ().code = yystack_[0].value.as < Attr > ().code;
        yylhs.value.as < Attr > ().lista.push_back(yystack_[0].value.as < Attr > ().tipo);

        yylhs.value.as < Attr > ().listaDir.push_back(yystack_[0].value.as < Attr > ().dir);
    }
#line 2402 "Parser.cpp"
    break;

  case 69: // ARGS: E COMMA ARGS
#line 1780 "parser.yy"
    {
        yylhs.value.as < Attr > ().code = yystack_[2].value.as < Attr > ().code;

        yylhs.value.as < Attr > ().code.insert(
            yylhs.value.as < Attr > ().code.end(),
            yystack_[0].value.as < Attr > ().code.begin(),
            yystack_[0].value.as < Attr > ().code.end()
        );
        yylhs.value.as < Attr > ().lista.push_back(yystack_[2].value.as < Attr > ().tipo);

        yylhs.value.as < Attr > ().listaDir.push_back(yystack_[2].value.as < Attr > ().dir);

        for(int t : yystack_[0].value.as < Attr > ().lista){
            yylhs.value.as < Attr > ().lista.push_back(t);
        }

        for(string d : yystack_[0].value.as < Attr > ().listaDir){
            yylhs.value.as < Attr > ().listaDir.push_back(d);
        }
    }
#line 2427 "Parser.cpp"
    break;

  case 70: // ARGS: %empty
#line 1804 "parser.yy"
    {
        yylhs.value.as < Attr > () = Attr();
    }
#line 2435 "Parser.cpp"
    break;


#line 2439 "Parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
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
    YY_STACK_PRINT ();
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -111;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
    -111,    10,    99,  -111,  -111,  -111,  -111,  -111,    24,     5,
      18,  -111,    99,    38,  -111,  -111,    43,  -111,  -111,  -111,
     -11,    27,    22,  -111,    99,    99,    51,    64,  -111,    99,
      37,    39,  -111,  -111,    47,    53,     5,  -111,    27,  -111,
      90,   -35,  -111,    91,  -111,     5,    57,  -111,     3,    94,
      76,  -111,    99,    95,  -111,  -111,    59,    60,    69,    78,
       2,    38,  -111,    73,     9,    76,  -111,  -111,  -111,     2,
       2,   110,  -111,  -111,  -111,  -111,    75,  -111,  -111,     2,
       2,    16,   202,    25,  -111,     2,   114,     2,  -111,   104,
     128,    96,     2,    85,   146,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,  -111,   118,  -111,
     220,  -111,   182,    76,    76,     2,   238,    97,  -111,     8,
       8,    85,    85,   317,   317,    -4,    -4,    -4,    -4,   305,
     292,  -111,  -111,  -111,   115,  -111,   256,     2,  -111,    76,
       2,  -111,  -111,   274,   134,   117,     2,   164,    76,  -111
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,    12,     1,    19,    20,    21,    22,     0,     0,
       0,     3,    12,     0,    15,     9,     0,    17,     7,    26,
       0,    24,     0,    13,    12,    12,     0,     0,    16,    12,
       0,     0,     8,    25,     0,     0,    29,    18,    24,    10,
       0,     0,    23,     6,    28,     0,     0,     4,     0,     0,
      32,    14,    12,     0,    27,    33,     0,     0,     0,     0,
       0,     0,    43,     0,     0,    32,    42,    11,     5,     0,
       0,     0,    41,    61,    62,    63,    33,    64,    65,     0,
       0,    66,     0,     0,    30,     0,     0,     0,    31,     0,
       0,     0,    70,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,    44,
       0,    35,     0,     0,     0,     0,    68,     0,    60,    46,
      47,    48,    49,    54,    55,    50,    52,    51,    53,    56,
      57,    59,    36,    34,    37,    39,     0,    70,    67,     0,
       0,    69,    38,     0,     0,     0,     0,     0,     0,    40
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -111,  -111,  -111,  -111,    -1,  -111,  -111,  -111,  -111,    -9,
    -111,  -111,  -111,   107,    86,  -111,   100,    88,   -49,  -110,
    -111,   -27,    17
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    48,    11,    22,    43,    12,    30,    13,
      21,    24,    14,    28,    20,    41,    62,    63,    81,    65,
      66,   116,   117
  };

  const unsigned char
  Parser::yytable_[] =
  {
      16,    64,    45,   134,   135,    73,    74,    75,    76,    46,
       3,    18,     4,     5,     6,     7,    64,    95,    96,    97,
      98,    77,    78,    31,    32,    25,    26,    40,    35,   142,
      15,    97,    98,    82,   108,    85,    49,    79,   149,    52,
      53,    61,    89,    90,    19,    80,   108,    86,    87,    23,
      10,    67,    93,    94,    86,    87,    61,    33,   110,    17,
     112,   109,    26,    29,    64,    64,    27,    34,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      36,    37,    55,     4,     5,     6,     7,    38,   136,    56,
      64,    57,    58,    59,    60,    39,    44,    47,    50,    64,
      54,    68,    69,    70,    61,    61,     4,     5,     6,     7,
       8,     9,    71,   143,    72,    84,    91,    50,    92,   147,
     111,    10,   115,   108,   131,    95,    96,    97,    98,   139,
      61,    99,   100,   101,   102,   103,   104,   105,   106,    61,
     145,   138,   108,   146,    10,    42,    51,    83,   113,    95,
      96,    97,    98,    88,   141,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   108,    95,    96,    97,
      98,     0,   114,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   108,    95,    96,    97,    98,     0,
     118,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   108,    95,    96,    97,    98,     0,   148,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     108,     0,   133,    95,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,     0,
     108,    95,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   132,     0,   108,    95,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   137,   108,    95,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   140,     0,   108,    95,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     144,     0,   108,    95,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,   104,   105,    95,    96,    97,    98,
     108,     0,    99,   100,   101,   102,   103,   104,    95,    96,
      97,    98,     0,   108,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,   108
  };

  const short
  Parser::yycheck_[] =
  {
       9,    50,    37,   113,   114,     3,     4,     5,     6,    44,
       0,    12,     7,     8,     9,    10,    65,    21,    22,    23,
      24,    19,    20,    24,    25,    36,    37,    36,    29,   139,
       6,    23,    24,    60,    38,    26,    45,    35,   148,    36,
      37,    50,    69,    70,     6,    43,    38,    38,    39,     6,
      45,    52,    79,    80,    38,    39,    65,     6,    85,    41,
      87,    36,    37,    41,   113,   114,    39,     3,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      43,    42,     6,     7,     8,     9,    10,    40,   115,    13,
     139,    15,    16,    17,    18,    42,     6,     6,    41,   148,
       6,     6,    43,    43,   113,   114,     7,     8,     9,    10,
      11,    12,    43,   140,    36,    42,     6,    41,    43,   146,
       6,    45,    26,    38,     6,    21,    22,    23,    24,    14,
     139,    27,    28,    29,    30,    31,    32,    33,    34,   148,
       6,    44,    38,    26,    45,    38,    46,    61,    44,    21,
      22,    23,    24,    65,   137,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    21,    22,    23,
      24,    -1,    44,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    21,    22,    23,    24,    -1,
      44,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    21,    22,    23,    24,    -1,    44,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    -1,    40,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      38,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    38,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    37,    38,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    38,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    38,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    21,    22,    23,    24,
      38,    -1,    27,    28,    29,    30,    31,    32,    21,    22,
      23,    24,    -1,    38,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    48,    49,     0,     7,     8,     9,    10,    11,    12,
      45,    51,    54,    56,    59,     6,    56,    41,    51,     6,
      61,    57,    52,     6,    58,    36,    37,    39,    60,    41,
      55,    51,    51,     6,     3,    51,    43,    42,    40,    42,
      56,    62,    60,    53,     6,    37,    44,     6,    50,    56,
      41,    63,    36,    37,     6,     6,    13,    15,    16,    17,
      18,    56,    63,    64,    65,    66,    67,    51,     6,    43,
      43,    43,    36,     3,     4,     5,     6,    19,    20,    35,
      43,    65,    68,    61,    42,    26,    38,    39,    64,    68,
      68,     6,    43,    68,    68,    21,    22,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    36,    38,    36,
      68,     6,    68,    44,    44,    26,    68,    69,    44,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,     6,    36,    40,    66,    66,    68,    37,    44,    14,
      36,    69,    66,    68,    36,     6,    26,    68,    44,    66
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    47,    49,    48,    50,    50,    50,    51,    51,    52,
      53,    51,    51,    55,    54,    57,    56,    58,    56,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      69
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     0,     2,     4,     0,
       0,    10,     0,     0,     8,     0,     3,     0,     5,     1,
       1,     1,     1,     4,     0,     3,     1,     4,     2,     0,
       3,     2,     0,     1,     4,     3,     4,     5,     7,     5,
      13,     2,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       0
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "FLOAT_LITERAL",
  "CHAR_LITERAL", "ID", "INT", "FLOAT", "BOOL", "CHAR", "STRUCT", "DEF",
  "IF", "ELSE", "WHILE", "FOR", "BREAK", "RETURN", "TRUE", "FALSE", "PLUS",
  "MINUS", "MULT", "DIV", "MOD", "ASSIGN", "EQ", "NEQ", "LT", "GT", "LE",
  "GE", "AND", "OR", "NOT", "SEMICOLON", "COMMA", "DOT", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "REGISTER",
  "LOWER_THAN_ELSE", "$accept", "P", "$@1", "STRUCT_VARS", "D", "$@2",
  "$@3", "FUNC", "$@4", "T", "$@5", "$@6", "B", "A", "L", "F", "BLOQUE",
  "S", "LVALUE", "STMT", "RETURN_STMT", "E", "ARGS", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   269,   269,   269,   296,   305,   314,   321,   325,   330,
     339,   329,   371,   385,   383,   455,   453,   470,   468,   516,
     523,   530,   537,   550,   567,   579,   605,   635,   642,   649,
     658,   670,   685,   691,   708,   743,   777,   793,   828,   878,
     924,  1004,  1011,  1019,  1023,  1037,  1064,  1100,  1136,  1173,
    1209,  1241,  1273,  1305,  1337,  1371,  1406,  1438,  1470,  1494,
    1566,  1577,  1589,  1601,  1611,  1621,  1629,  1641,  1767,  1778,
    1804
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
    };
    // Last valid token kind.
    const int code_max = 301;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 13 "parser.yy"
} // C1
#line 3090 "Parser.cpp"

#line 1809 "parser.yy"


// ============================================================
// MANEJO DE ERRORES
// ============================================================

void C1::Parser::error(const std::string& msg){
    cerr << "Error sintáctico: "
         << msg
         << " cerca de token: '"
         << lexer->YYText()  // shows the actual token text
         << "' en línea "
         << lexer->lineno()  // shows line number
         << endl;
}
