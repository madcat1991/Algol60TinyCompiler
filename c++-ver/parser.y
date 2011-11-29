%start program
%token TBEGIN TEND
%token TOWN TREAL TINTEGER TBOOLEAN TARRAY TSWITCH TPROCEDURE
%token TSTRING TLABEL TVALUE
%token TSTEP TUNTIL TWHILE TCOMMENT
%token TGOTO TIF TTHEN TELSE TFOR TDO 
%token TEQUIV TIMPL TOR TAND TNOT
%token TLESS TNOTGREATER TEQUAL TNOTLESS TGREATER TNOTEQUAL
%token TTRUE TFALSE
%token TPOWER 
%token TANY_SYMBOL_SEQ_WO_QUOTE 
%token TDIGIT
%token TLETTER
%token TASSIGN
%left '+' '-' '*' '/' '%'
%right 'e' '^'

%%

program : block | compound_statement ;
block : unlabelled_block | label ':' block ;
unlabelled_block : block_head ';' compound_tail ;
block_head : TBEGIN declaration | block_head ';' declaration ;
compound_statement : unlabelled_compound | label ':' compound_statement ;
		unlabelled_compound : TBEGIN compound_tail ;
		compound_tail : statement TEND | statement ';' compound_tail ;

declaration : type_declaration | array_declaration | switch_declaration | procedure_declaration ;
	type_declaration : local_or_own_type type_list ;
		local_or_own_type : type | TOWN type ;
			type : TREAL | TINTEGER | TBOOLEAN ;
		type_list : simple_variable | simple_variable ',' type_list ;
	array_declaration : TARRAY array_list | local_or_own_type TARRAY array_list ;
		array_list : array_segment | array_list ',' array_segment ;
			array_segment : array_identifier '[' bound_pair_list ']' | array_identifier ',' array_segment ;
				array_identifier : identifier ;
				bound_pair_list : bound_pair |  bound_pair_list ',' bound_pair ;
					bound_pair : lower_bound ':' upper_bound ;
						upper_bound : arithmetic_expression ;
						lower_bound : arithmetic_expression ;
	switch_declaration : TSWITCH switch_identifier TASSIGN switch_list ;
		switch_identifier : identifier ;
		switch_list : designational_expression | switch_list ',' designational_expression ;
	procedure_declaration : TPROCEDURE procedure_heading procedure_body | type TPROCEDURE procedure_heading procedure_body ;
		procedure_heading : procedure_identifier formal_parameter_part ';' value_part specification_part ;
			procedure_identifier : identifier ;
			formal_parameter_part :  | '(' formal_parameter_list ')' ;
				formal_parameter_list : formal_parameter | formal_parameter_list parameter_delimiter formal_parameter ;
					formal_parameter : identifier  ;
			value_part : | TVALUE identifier_list ';' ;
			specification_part :  | specifier identifier_list ';' | specification_part specifier identifier_list ;
				specifier : TSTRING | type | TARRAY | type TARRAY | TLABEL | TSWITCH | TPROCEDURE | type TPROCEDURE ;
				identifier_list : identifier | identifier_list ',' identifier ;
		procedure_body : statement;

statement : unconditional_statement | conditional_statement | for_statement ;
	unconditional_statement : basic_statement | compound_statement | block ;
		basic_statement : unlabelled_basic_statement | label':' basic_statement ;
			label : identifier | unsigned_integer ;
			unlabelled_basic_statement : | assignment_statement | go_to_statement | procedure_statement ;
				assignment_statement : left_part_list arithmetic_expression | left_part_list boolean_expression ;
					left_part_list : left_part | left_part_list left_part ;
						left_part : variable TASSIGN | procedure_identifier TASSIGN ;
				go_to_statement : TGOTO designational_expression ;
					designational_expression : simple_designational_expression |
					                               if_clause simple_designational_expression TELSE designational_expression ;
					simple_designational_expression : label | switch_designator | '('designational_expression')' ;
						switch_designator : switch_identifier '['subscript_expression']' ;
				procedure_statement : procedure_identifier actual_parameter_part ;
					actual_parameter_part : | '(' actual_parameter_list ')' ;
						actual_parameter_list : actual_parameter | actual_parameter_list parameter_delimiter actual_parameter ;
							parameter_delimiter : ',' | ')' letter_string ':' '(' ;
							actual_parameter : string | expression | array_identifier | switch_identifier | procedure_identifier ;
	conditional_statement : if_statement | if_statement TELSE statement | if_clause for_statement | label':' conditional_statement ;
		if_statement : if_clause unconditional_statement ;
			if_clause : TIF boolean_expression TTHEN ;
	for_statement : for_clause statement | label':' for_statement ;
		for_clause : TFOR variable TASSIGN for_list TDO ;
			for_list : for_list_element | for_list ',' for_list_element ;
				for_list_element : arithmetic_expression |
				                       arithmetic_expression TSTEP arithmetic_expression TUNTIL arithmetic_expression |
				                       arithmetic_expression TWHILE boolean_expression ;

expression : arithmetic_expression | boolean_expression | designational_expression ;
	arithmetic_expression : simple_arithmetic_expression | if_clause simple_arithmetic_expression TELSE arithmetic_expression ;
		simple_arithmetic_expression : term | adding_operator term | simple_arithmetic_expression adding_operator term ;
			adding_operator : '+' | '-' ;
			term : factor | term multiplying_operator factor ;
				multiplying_operator : '*' | '/' | '%' ;
				factor : primary | factor | factor TPOWER primary ;
					primary : unsigned_number | variable | function_designator | '(' arithmetic_expression ')' ;
						unsigned_number : decimal_number | exponential_part | decimal_number exponential_part ;
							decimal_number : unsigned_integer | decimal_fraction | unsigned_integer decimal_fraction ;
								unsigned_integer : TDIGIT | unsigned_integer TDIGIT ;
								decimal_fraction : '.' unsigned_integer ;
							exponential_part : 'e' integer ;
								integer : unsigned_integer | '+' unsigned_integer | '-' unsigned_integer ;
	boolean_expression : simple_boolean | if_clause simple_boolean TELSE boolean_expression ;
		simple_boolean : implication | simple_boolean TEQUIV implication ;
			implication : boolean_term | implication TIMPL boolean_term ;
				boolean_term : boolean_factor | boolean_term TOR boolean_factor ;
				boolean_factor : boolean_secondary | boolean_factor TAND boolean_secondary ;
					boolean_secondary : boolean_primary | TNOT boolean_primary ;
						boolean_primary : logical_value | variable | function_designator | relation | '(' boolean_expression ')' ;
							relation : simple_arithmetic_expression relational_operator simple_arithmetic_expression ;
								relational_operator : '<' | '=' | '>' | TLESS | TNOTGREATER | TEQUAL | TNOTLESS | TGREATER | TNOTEQUAL ;
							function_designator : procedure_identifier actual_parameter_part ;

variable : simple_variable | subscripted_variable ;
	simple_variable : variable_identifier ;
			variable_identifier : identifier ;
subscripted_variable : array_identifier '[' subscript_list ']' ;
	subscript_list : subscript_expression | subscript_list ',' subscript_expression ;
		subscript_expression : arithmetic_expression ;

string : '"'open_string'"' ;
	open_string : proper_string '"'open_string'"' | open_string open_string ;
	proper_string : | TANY_SYMBOL_SEQ_WO_QUOTE ;

letter_string : TLETTER | letter_string TLETTER ;

identifier : TLETTER | identifier TLETTER | identifier TDIGIT ;

basic_symbol : TLETTER | TDIGIT | logical_value | delimiter ;

logical_value : TTRUE | TFALSE ;

delimiter : operator | separator | bracket | declarator | specificator ;

operator : arithmetic_operator | relational_operator | logical_operator | sequential_operator ;
arithmetic_operator : '+' | '-' | '*' | '/' | '%' | TPOWER ;
relational_operator : '<' | '=' | '>' | TLESS | TNOTGREATER | TEQUAL | TNOTLESS | TGREATER | TNOTEQUAL ;
logical_operator : TEQUIV | TIMPL | TOR | TAND | TNOT ;
sequential_operator : TGOTO | TIF | TTHEN | TELSE | TFOR | TDO ;

separator : ',' | '.' | 'e' | ':' | ';' | TASSIGN | '_' | TSTEP | TUNTIL | TWHILE | TCOMMENT ;
bracket : '(' | ')' | '[' | ']' | '`' | '\'' | TBEGIN | TEND ;
declarator : TOWN | TBOOLEAN | TINTEGER | TREAL | TARRAY | TSWITCH | TPROCEDURE ;
specificator : TSTRING | TLABEL | TVALUE ;

%%

main( int argc, char *argv[] )
{ 
    extern FILE *yyin;
    ++argv; 
    --argc;
    yyin = fopen( argv[0], "r" );
    yydebug = 1;
    errors = 0;
    yyparse();
}
    yyerror(char *s) /* Called by yyparse on error */
{
    printf ("%s\n", s);
}
