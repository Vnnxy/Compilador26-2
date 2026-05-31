// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 29 "parser.yy" // lalr1.cc:413

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 64 "parser.tab.cc" // lalr1.cc:413


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
    while (/*CONSTCOND*/ false)
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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy" // lalr1.cc:479
namespace C0 {
#line 150 "parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 41: // expresion
      case 42: // condicion
        value.copy< Expresion > (other.value);
        break;

      case 37: // type
        value.copy< int > (other.value);
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 41: // expresion
      case 42: // condicion
        value.copy< Expresion > (v);
        break;

      case 37: // type
        value.copy< int > (v);
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Expresion v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 41: // expresion
      case 42: // condicion
        value.template destroy< Expresion > ();
        break;

      case 37: // type
        value.template destroy< int > ();
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 41: // expresion
      case 42: // condicion
        value.move< Expresion > (s.value);
        break;

      case 37: // type
        value.move< int > (s.value);
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

  Parser::symbol_type
  Parser::make_NUMERO (const std::string& v, const location_type& l)
  {
    return symbol_type (token::NUMERO, v, l);
  }

  Parser::symbol_type
  Parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }

  Parser::symbol_type
  Parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  Parser::symbol_type
  Parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

  Parser::symbol_type
  Parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

  Parser::symbol_type
  Parser::make_PUTS (const location_type& l)
  {
    return symbol_type (token::PUTS, l);
  }

  Parser::symbol_type
  Parser::make_PUTW (const location_type& l)
  {
    return symbol_type (token::PUTW, l);
  }

  Parser::symbol_type
  Parser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::BREAK, l);
  }

  Parser::symbol_type
  Parser::make_INT (const location_type& l)
  {
    return symbol_type (token::INT, l);
  }

  Parser::symbol_type
  Parser::make_VOID (const location_type& l)
  {
    return symbol_type (token::VOID, l);
  }

  Parser::symbol_type
  Parser::make_LKEY (const location_type& l)
  {
    return symbol_type (token::LKEY, l);
  }

  Parser::symbol_type
  Parser::make_RKEY (const location_type& l)
  {
    return symbol_type (token::RKEY, l);
  }

  Parser::symbol_type
  Parser::make_PYC (const location_type& l)
  {
    return symbol_type (token::PYC, l);
  }

  Parser::symbol_type
  Parser::make_ASIG (const location_type& l)
  {
    return symbol_type (token::ASIG, l);
  }

  Parser::symbol_type
  Parser::make_OR (const location_type& l)
  {
    return symbol_type (token::OR, l);
  }

  Parser::symbol_type
  Parser::make_AND (const location_type& l)
  {
    return symbol_type (token::AND, l);
  }

  Parser::symbol_type
  Parser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_DISTINCT (const location_type& l)
  {
    return symbol_type (token::DISTINCT, l);
  }

  Parser::symbol_type
  Parser::make_LT (const location_type& l)
  {
    return symbol_type (token::LT, l);
  }

  Parser::symbol_type
  Parser::make_GT (const location_type& l)
  {
    return symbol_type (token::GT, l);
  }

  Parser::symbol_type
  Parser::make_MAS (const location_type& l)
  {
    return symbol_type (token::MAS, l);
  }

  Parser::symbol_type
  Parser::make_MENOS (const location_type& l)
  {
    return symbol_type (token::MENOS, l);
  }

  Parser::symbol_type
  Parser::make_MUL (const location_type& l)
  {
    return symbol_type (token::MUL, l);
  }

  Parser::symbol_type
  Parser::make_DIV (const location_type& l)
  {
    return symbol_type (token::DIV, l);
  }

  Parser::symbol_type
  Parser::make_LPAR (const location_type& l)
  {
    return symbol_type (token::LPAR, l);
  }

  Parser::symbol_type
  Parser::make_RPAR (const location_type& l)
  {
    return symbol_type (token::RPAR, l);
  }



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 41: // expresion
      case 42: // condicion
        value.move< Expresion > (that.value);
        break;

      case 37: // type
        value.move< int > (that.value);
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 41: // expresion
      case 42: // condicion
        value.copy< Expresion > (that.value);
        break;

      case 37: // type
        value.copy< int > (that.value);
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
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

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
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
    yypush_ ("Shifting", yyn, yyla);
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
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 41: // expresion
      case 42: // condicion
        yylhs.value.build< Expresion > ();
        break;

      case 37: // type
        yylhs.value.build< int > ();
        break;

      case 3: // ID
      case 4: // NUMERO
      case 5: // STRING
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 67 "parser.yy" // lalr1.cc:859
    {
            driver.init();
    }
#line 925 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 71 "parser.yy" // lalr1.cc:859
    {
        driver.printSymTab();
    }
#line 933 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 87 "parser.yy" // lalr1.cc:859
    {
        driver.current_type=yystack_[0].value.as< int > ();
    }
#line 941 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 90 "parser.yy" // lalr1.cc:859
    {
        if(driver.isInSymbol(yystack_[1].value.as< std::string > ())){
            std::cout<<"Error variable ya declarada"<<std::endl;
        }else{
            driver.addSymbol(yystack_[1].value.as< std::string > ());
            driver.direcciones+=4;
            driver.setDir(yystack_[1].value.as< std::string > (), driver.direcciones);
            driver.setType(yystack_[1].value.as< std::string > (), driver.current_type);
            driver.setVar(yystack_[1].value.as< std::string > (),"var");
        }
    }
#line 957 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 103 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< int > ()=0;
    }
#line 965 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 110 "parser.yy" // lalr1.cc:859
    {          
        driver.printCI();
        driver.generateStrings();
        driver.translate();    
    }
#line 975 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 129 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.add(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 981 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 130 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.sub(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 987 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 131 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.mul(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 993 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 132 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.div(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 999 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 133 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< Expresion > ()=yystack_[1].value.as< Expresion > ();}
#line 1005 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 134 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.number(yystack_[0].value.as< std::string > ());}
#line 1011 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 135 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.ident(yystack_[0].value.as< std::string > ());}
#line 1017 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 139 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver._or(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1023 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 140 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver._and(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1029 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 141 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.equal(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1035 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 142 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.distinct(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1041 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 143 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.gt(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1047 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 144 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=driver.lt(yystack_[2].value.as< Expresion > (), yystack_[0].value.as< Expresion > ());}
#line 1053 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 145 "parser.yy" // lalr1.cc:859
    {yylhs.value.as< Expresion > ()=yystack_[1].value.as< Expresion > ();}
#line 1059 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 150 "parser.yy" // lalr1.cc:859
    {
        driver.numIf++;
        driver.iStack->push(driver.numIf);
    }
#line 1068 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 155 "parser.yy" // lalr1.cc:859
    {
         driver._if(yystack_[0].value.as< Expresion > (), driver.iStack->top());
         
     }
#line 1077 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 160 "parser.yy" // lalr1.cc:859
    {
        driver._goto("Lei",driver.iStack->top());
        driver._label("Le", driver.iStack->top());
    }
#line 1086 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 165 "parser.yy" // lalr1.cc:859
    {
        driver._label("Lei", driver.iStack->top());
        driver.iStack->pop();
    }
#line 1095 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 178 "parser.yy" // lalr1.cc:859
    {
        driver.numWhile++;
        driver.wStack->push(driver.numWhile);
        driver._label("InicioWhile", driver.wStack->top());

    }
#line 1106 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 185 "parser.yy" // lalr1.cc:859
    {
        driver._while(yystack_[0].value.as< Expresion > (), driver.wStack->top());
     }
#line 1114 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 189 "parser.yy" // lalr1.cc:859
    {
        driver.numWhile2++;
    }
#line 1122 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 193 "parser.yy" // lalr1.cc:859
    {
        driver.numWhile2--;
     }
#line 1130 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 197 "parser.yy" // lalr1.cc:859
    {
        driver._goto("InicioWhile", driver.wStack->top());
        driver._label("FinWhile", driver.wStack->top());
        driver.wStack->pop();
     }
#line 1140 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 206 "parser.yy" // lalr1.cc:859
    {
        if(!driver.isInSymbol(yystack_[0].value.as< std::string > ())){
            std::cout<<"Error la varaible no fue declarada es:"<<yystack_[0].value.as< std::string > ()<<endl;
        }
    }
#line 1150 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 212 "parser.yy" // lalr1.cc:859
    {
        driver.asign(yystack_[4].value.as< std::string > (), yystack_[1].value.as< Expresion > ());
    }
#line 1158 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 220 "parser.yy" // lalr1.cc:859
    {
        driver.writew(yystack_[0].value.as< Expresion > ());
    }
#line 1166 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 228 "parser.yy" // lalr1.cc:859
    {
        driver.writes(yystack_[0].value.as< std::string > (), driver.numString);
        driver.numString++;
    }
#line 1175 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 237 "parser.yy" // lalr1.cc:859
    {
        if(driver.numWhile2 <=0)              
            cout<<"Error no se puede poner un break sin while"<<endl;
    }
#line 1184 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1188 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
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
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -57;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -10,    10,     9,    15,   -57,     4,   -57,   -57,    15,   -57,
     -57,    13,   -10,   -57,    36,    33,   -57,    41,    35,   -57,
     -57,    52,    53,    54,    55,   -57,    56,    35,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,    62,   -57,   -57,    79,    -2,
      69,   -57,   -57,    -2,     8,     8,   -57,   -57,   -57,    -2,
      49,   -57,    -8,     8,    39,   -13,   -13,    57,    43,    -2,
      -2,    -2,    -2,    58,   -57,    29,     6,    -2,    -2,    -2,
      -2,     8,     8,    59,    60,    74,   -57,    51,    51,   -57,
     -57,    75,   -57,    49,    49,    49,    49,    73,   -57,    80,
      81,   -57,   -57,    35,   -57,    78,    35,   -57,   -57,    89,
      82,    84,   -57,   -57,    35,    85,   -57
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       2,     0,     0,     0,     5,     0,     1,    10,     3,     7,
       8,     0,     0,     6,     0,     0,     4,     0,    13,     9,
      41,     0,     0,     0,     0,    47,     0,    12,    49,    50,
      51,    52,    53,    54,    15,     0,    30,    36,     0,     0,
       0,    11,    14,     0,     0,     0,    45,    22,    21,     0,
      43,    48,     0,     0,     0,    31,    37,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    16,    17,    18,
      19,     0,    29,    25,    26,    28,    27,    23,    24,     0,
       0,    46,    44,    13,    38,     0,    13,    32,    39,    35,
       0,     0,    33,    40,    13,     0,    34
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -57,   -57,   -57,   -57,   -57,    91,   -57,   -57,    90,   -56,
     -57,   -39,   -38,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,    76
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,    12,     8,     9,    14,    10,     4,    26,
      27,    54,    55,    28,    44,    73,    99,   102,    29,    45,
      74,    96,   100,    30,    35,    31,    63,    32,    57,    33,
      40,    34
  };

  const unsigned char
  Parser::yytable_[] =
  {
      50,    47,    48,     1,    52,    71,    72,    56,    64,     6,
      58,    47,    48,     5,    65,    66,    59,    60,    61,    62,
      77,    78,    79,    80,    71,    72,    49,     7,    83,    84,
      85,    86,    11,    87,    88,    82,    53,    95,    20,    17,
      98,    21,    15,    22,    23,    24,    25,    18,   105,    67,
      68,    69,    70,    59,    60,    61,    62,    19,    76,    67,
      68,    69,    70,    59,    60,    61,    62,    59,    60,    61,
      62,    41,    76,    59,    60,    61,    62,    61,    62,    43,
      36,    37,    38,    39,    46,    51,    75,    81,    89,    90,
      91,    92,    72,    97,    93,    94,   101,   103,   104,    13,
     106,     0,    16,    42
  };

  const signed char
  Parser::yycheck_[] =
  {
      39,     3,     4,    13,    43,    18,    19,    45,    16,     0,
      49,     3,     4,     3,    53,    53,    24,    25,    26,    27,
      59,    60,    61,    62,    18,    19,    28,    12,    67,    68,
      69,    70,    28,    71,    72,    29,    28,    93,     3,     3,
      96,     6,    29,     8,     9,    10,    11,    14,   104,    20,
      21,    22,    23,    24,    25,    26,    27,    16,    29,    20,
      21,    22,    23,    24,    25,    26,    27,    24,    25,    26,
      27,    15,    29,    24,    25,    26,    27,    26,    27,    17,
      28,    28,    28,    28,     5,    16,    29,    29,    29,    29,
      16,    16,    19,    15,    14,    14,     7,    15,    14,     8,
      15,    -1,    12,    27
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    13,    31,    32,    38,     3,     0,    12,    34,    35,
      37,    28,    33,    35,    36,    29,    38,     3,    14,    16,
       3,     6,     8,     9,    10,    11,    39,    40,    43,    48,
      53,    55,    57,    59,    61,    54,    28,    28,    28,    28,
      60,    15,    61,    17,    44,    49,     5,     3,     4,    28,
      41,    16,    41,    28,    41,    42,    42,    58,    41,    24,
      25,    26,    27,    56,    16,    41,    42,    20,    21,    22,
      23,    18,    19,    45,    50,    29,    29,    41,    41,    41,
      41,    29,    29,    41,    41,    41,    41,    42,    42,    29,
      29,    16,    16,    14,    14,    39,    51,    15,    39,    46,
      52,     7,    47,    15,    14,    39,    15
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    30,    32,    33,    31,    31,    34,    34,    36,    35,
      37,    38,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    42,    42,    42,    42,    42,
      44,    45,    46,    43,    47,    47,    49,    50,    51,    52,
      48,    54,    53,    56,    55,    58,    57,    60,    59,    61,
      61,    61,    61,    61,    61
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     0,     0,     4,     1,     2,     1,     0,     4,
       1,     7,     1,     0,     2,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       0,     0,     0,    11,     4,     0,     0,     0,     0,     0,
      11,     0,     5,     0,     6,     0,     6,     0,     3,     1,
       1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "ID", "NUMERO", "STRING", "IF", "ELSE",
  "WHILE", "PUTS", "PUTW", "BREAK", "INT", "VOID", "LKEY", "RKEY", "PYC",
  "ASIG", "OR", "AND", "EQUAL", "DISTINCT", "LT", "GT", "MAS", "MENOS",
  "MUL", "DIV", "LPAR", "RPAR", "$accept", "program", "$@1", "$@2",
  "declaraciones", "declaracion", "$@3", "type", "funcion",
  "bloqueSentencias", "sentencias", "expresion", "condicion", "sentIf",
  "$@4", "$@5", "$@6", "sentElse", "sentWhile", "$@7", "$@8", "$@9",
  "$@10", "sentAsig", "$@11", "sentPutw", "$@12", "sentPuts", "$@13",
  "sentBreak", "$@14", "sentencia", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    67,    67,    71,    67,    76,    81,    82,    87,    86,
     103,   109,   118,   119,   123,   125,   129,   130,   131,   132,
     133,   134,   135,   139,   140,   141,   142,   143,   144,   145,
     150,   155,   160,   149,   172,   173,   178,   185,   189,   193,
     177,   206,   205,   220,   219,   228,   227,   237,   236,   245,
     246,   247,   248,   249,   250
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
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
      25,    26,    27,    28,    29
    };
    const unsigned int user_token_number_max_ = 284;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.yy" // lalr1.cc:1167
} // C0
#line 1589 "parser.tab.cc" // lalr1.cc:1167
#line 252 "parser.yy" // lalr1.cc:1168


void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
