%start program
%token BEGIN END
%token OWN REAL INTEGER BOOLEAN ARRAY SWITCH PROCEDURE
%token STRING LABEL VALUE
%token STEP UNTIL WHILE COMMENT
%token GOTO IF THEN ELSE FOR DO 
%token EQUIV IMPL OR AND NOT
%token LESS NOTGREATER EQUAL NOTLESS GREATER NOTEQUAL
%token TRUE FALSE
%token POWER 
%token ANY_SYMBOL_SEQ_WO_QUOTE 
%left '+' '-' '*' '/' '÷'
%right 'e' '^'

%%

program : block | compound_statement ;
block : unlabelled_block | label ':' block ;
unlabelled_block : block_head ';' compound_tail ;
block_head : BEGIN declaration | block_head ';' declaration ;
compound_statement : unlabelled_compound | label ':' compound_statement ;
		unlabelled_compound : BEGIN compound_tail ;
		compound_tail : statement END | statement ';' compound_tail ;

declaration : type_declaration | array_declaration | switch_declaration | procedure_declaration ;
	type_declaration : local_or_own_type type_list ;
		local_or_own_type : type | OWN type ;
			type : REAL | INTEGER | BOOLEAN ;
		type_list : simple_variable | simple_variable ',' type_list ;
	array_declaration : ARRAY array_list | local_or_own_type ARRAY array_list ;
		array_list : array_segment | array_list ',' array_segment ;
			array_segment : array_identifier '[' bound_pair_list ']' | array_identifier ',' array_segment ;
				array_identifier : identifier ;
				bound_pair_list : bound_pair |  bound_pair_list ',' bound_pair ;
					bound_pair : lower_bound : upper_bound ;
						upper_bound : arithmetic_expression ;
						lower_bound : arithmetic_expression ;
	switch_declaration : SWITCH switch_identifier ':=' switch_list ;
		switch_identifier : identifier ;
		switch_list : designational_expression | switch_list ',' designational_expression ;
	procedure_declaration : PROCEDURE procedure_heading procedure_body | type PROCEDURE procedure_heading procedure_body ;
		procedure_heading : procedure_identifier formal_parameter_part ';' value_part specification_part ;
			procedure_identifier : identifier ;
			formal_parameter_part :  | '(' formal_parameter_list ')' ;
				formal_parameter_list : formal_parameter | formal_parameter_list parameter_delimiter formal_parameter ;
					formal_parameter : identifier  ;
			value_part : | VALUE identifier_list ';' ;
			specification_part :  | specifier identifier_list ';' | specification_part specifier identifier_list ;
				specifier : STRING | type | ARRAY | type ARRAY | LABEL | SWITCH | PROCEDURE | type PROCEDURE ;
				identifier_list : identifier | identifier_list ',' identifier ;
		procedure_body : statement;

statement : unconditional_statement | conditional_statement | for_statement ;
	unconditional_statement : basic_statement | compound_statement | block ;
		basic_statement : unlabelled_basic_statement | label':' basic_statement ;
			label : identifier | unsigned_integer ;
			unlabelled_basic_statement : | assignment_statement | go_to_statement | procedure_statement ;
				assignment_statement : left_part_list arithmetic_expression | left_part_list boolean_expression ;
					left_part_list : left_part | left_part_list left_part ;
						left_part : variable ':=' | procedure_identifier ':=' ;
				go_to_statement : GOTO designational_expression ;
					designational_expression : simple_designational_expression |
					                               if_clause simple_designational_expression ELSE designational_expression ;
					simple_designational_expression : label | switch_designator | '('designational_expression')' ;
						switch_designator : switch_identifier '['subscript_expression']' ;
				procedure_statement : procedure_identifier actual_parameter_part ;
					actual_parameter_part : | '(' actual_parameter_list ')' ;
						actual_parameter_list : actual_parameter | actual_parameter_list parameter_delimiter actual_parameter ;
							parameter_delimiter : ',' | ')' letter_string ':' '(' ;
							actual_parameter : string | expression | array_identifier | switch_identifier | procedure_identifier ;
	conditional_statement : if_statement | if_statement ELSE statement | if_clause for_statement | label':' conditional_statement ;
		if_statement : if_clause unconditional_statement ;
			if_clause : IF boolean_expression THEN ;
	for_statement : for_clause statement | label':' for_statement ;
		for_clause : FOR variable ':=' for_list DO ;
			for_list : for_list_element | for_list ',' for_list_element ;
				for_list_element : arithmetic_expression |
				                       arithmetic_expression STEP arithmetic_expression UNTIL arithmetic_expression |
				                       arithmetic_expression WHILE boolean_expression ;

expression : arithmetic_expression | boolean_expression | designational_expression ;
	arithmetic_expression : simple_arithmetic_expression | if_clause simple_arithmetic_expression ELSE arithmetic_expression ;
		simple_arithmetic_expression : term | adding_operator term | simple_arithmetic_expression adding_operator term ;
			adding_operator : '+' | '-' ;
			term : factor | term multiplying_operator factor ;
				multiplying_operator : '*' | '/' | '÷' ;
				factor : primary | factor | factor POWER primary ;
					primary : unsigned_number | variable | function_designator | '(' arithmetic_expression ')' ;
						unsigned_number : decimal_number | exponential_part | decimal_number exponential_part ;
							decimal_number : unsigned_integer | decimal_fraction | unsigned_integer decimal_fraction ;
								unsigned_integer : digit | unsigned_integer digit ;
								decimal_fraction : '.' unsigned_integer ;
							exponential_part : 'e' integer ;
								integer : unsigned_integer | '+' unsigned_integer | '-' unsigned_integer ;
	boolean_expression : simple_boolean | if_clause simple_boolean ELSE boolean_expression ;
		simple_boolean : implication | simple_boolean EQUIV implication ;
			implication : boolean_term | implication IMPL boolean_term ;
				boolean_term : boolean_factor | boolean_term OR boolean_factor ;
				boolean_factor : boolean_secondary | boolean_factor AND boolean_secondary ;
					boolean_secondary : boolean_primary | NOT boolean_primary ;
						boolean_primary : logical_value | variable | function_designator | relation | '(' boolean_expression ')' ;
							relation : simple_arithmetic_expression relational_operator simple_arithmetic_expression ;
								relational_operator : '<' | '¾' | '=' | '„' | '>' | '‚' |
								                          LESS | NOTGREATER | EQUAL | NOTLESS | GREATER | NOTEQUAL ;
							function_designator : procedure_identifier actual_parameter_part ;

variable : simple_variable | subscripted_variable ;
	simple_variable : variable_identifier ;
			variable_identifier : identifier ;
subscripted_variable : array_identifier '[' subscript_list ']' ;
	subscript_list : subscript_expression | subscript_list ',' subscript_expression ;
		subscript_expression : arithmetic_expression ;

string : '"'open_string'"' ;
	open_string : proper_string '"'open_string'"' | open_string open_string ;
	proper_string : | ANY_SYMBOL_SEQ_WO_QUOTE ;

letter_string : letter | letter_string letter ;

identifier : letter | identifier letter | identifier digit ;

basic_symbol : letter | digit | logical_value | delimiter ;

letter : 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' |
             'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z' | 'A' |
             'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' | 'N' | 'O' | 'P' |
             'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z' ;
digit : '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'  ;
logical_value : TRUE | FALSE ;

delimiter : operator | separator | bracket | declarator | specificator ;

operator : arithmetic_operator | relational_operator | logical_operator | sequential_operator ;
arithmetic_operator : '+' | '-' | '*' | '/' | '÷' | POWER ;
relational_operator : '<' | '¾' | '=' | '„' | '>' | '‚' |
                          LESS | NOTGREATER | EQUAL | NOTLESS | GREATER | NOTEQUAL ;
logical_operator : EQUIV | IMPL | OR | AND | NOT ;
sequential_operator : GOTO | IF | THEN | ELSE | FOR | DO ;

separator : ',' | '.' | 'e' | ':' | ';' | ':=' | '_' | STEP | UNTIL | WHILE | COMMENT ;
bracket : '(' | ')' | '[' | ']' | '`' | '\'' | BEGIN | END ;
declarator : OWN | BOOLEAN | INTEGER | REAL | ARRAY | SWITCH | PROCEDURE ;
specificator : STRING | LABEL | VALUE ;
%%
main( int argc, char *argv[] )
{ 
    extern FILE *yyin;
    ++argv; ??argc;
    yyin = fopen( argv[0], ”r” );
    yydebug = 1;
    errors = 0;
    yyparse ();
}
    yyerror (char *s) /* Called by yyparse on error */
{
    printf (”%s\n”, s);
}