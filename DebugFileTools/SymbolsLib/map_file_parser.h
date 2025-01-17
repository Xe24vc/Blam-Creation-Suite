#pragma once

struct t_symbol_file_parser;
BCS_RESULT symbol_file_parser_create(
	const wchar_t* mapping_filepath, 
	const char** excluded_libs, 
	unsigned long excluded_libs_count,
	t_symbol_file_parser*& symbol_file_parser
);

BCS_RESULT symbol_file_parser_write_output(t_symbol_file_parser* symbol_file_parser, const wchar_t* output_filepath);
BCS_RESULT symbol_file_parser_get_symbol_data(t_symbol_file_parser* symbol_file_parser, const char*& symbol_data, unsigned long& symbol_data_size);
BCS_RESULT symbol_file_parser_get_symbol_data_size(t_symbol_file_parser* symbol_file_parser, unsigned long& symbol_data_size);
BCS_RESULT symbol_file_parser_destroy(t_symbol_file_parser* symbol_file_parser);
