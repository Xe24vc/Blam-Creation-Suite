#include "blamboozlelib-private-pch.h"

uint64_t make_tool_version_runtime(uint64_t library_file_version, const wchar_t* library_description, const wchar_t* library_product_name)
{
	//#define MAKE_TOOL_VERSION(a, b, c, d, file_description, product_name) (MAKE_FILE_VERSION(a, b, c, d) ^ (file_description##product_name##_xxh64))
	//	_build_halo1_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 609, "Guerilla MFC Application", "Guerilla Application"),
	//	_build_halo2_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 0, "Tag Editor", "Halo 2 for Windows Vista"),

	char buffer[1024]{};
	snprintf(buffer, _countof(buffer) - 1, "%S%S", library_description, library_product_name);

	uint64_t hash = xxh64(buffer, strlen(buffer));
	uint64_t result = library_file_version ^ hash;

	return result;
}

int blamboozle_run()
{
	const wchar_t* output_directory;
	if (BCS_FAILED(command_line_get_argument(L"blamboozle-output", output_directory)))
	{
		console_write_line("No output directory specified");
		console_write_line("Usage <output directory> <binary ...>");
		return 1;
	}


	const wchar_t* halo1_guerilla_file;
	const wchar_t* halo2_guerilla_file;
	const wchar_t* halo3_guerilla_file;
	const wchar_t* reach_tags_test_360_file;
	const wchar_t* halo4_midnight_tags_test;
	const wchar_t* halo5_forge_file;
	const wchar_t* infinite_flight1_preview_file;
	const wchar_t* infinite_flight2_preview_file;
	const wchar_t* infinite_release_file;

	BCS_RESULT rs_halo1_guerilla			= command_line_get_argument(L"blamboozle-halo1-guerilla",				halo1_guerilla_file);
	BCS_RESULT rs_halo2_guerilla			= command_line_get_argument(L"blamboozle-halo2-guerilla",				halo2_guerilla_file);
	BCS_RESULT rs_halo3_guerilla			= command_line_get_argument(L"blamboozle-halo3-guerilla",				halo3_guerilla_file);
	BCS_RESULT rs_reach_tags_test_360		= command_line_get_argument(L"blamboozle-haloreach",					reach_tags_test_360_file);
	BCS_RESULT rs_halo4_tags_test			= command_line_get_argument(L"blamboozle-halo4-tag-test",				halo4_midnight_tags_test);
	BCS_RESULT rs_halo5_forge				= command_line_get_argument(L"blamboozle-halo5-forge",					halo5_forge_file);
	BCS_RESULT rs_infinite_flight1_preview	= command_line_get_argument(L"blamboozle-infinite-flight1",				infinite_flight1_preview_file);
	BCS_RESULT rs_infinite_flight2_preview	= command_line_get_argument(L"blamboozle-infinite-flight2",				infinite_flight2_preview_file);
	BCS_RESULT rs_infinite_release			= command_line_get_argument(L"blamboozle-infinite-release",				infinite_release_file);
	

	if(
		BCS_FAILED(rs_halo1_guerilla) &&
		BCS_FAILED(rs_halo2_guerilla) &&
		BCS_FAILED(rs_halo3_guerilla) &&
		BCS_FAILED(rs_reach_tags_test_360) &&
		BCS_FAILED(rs_halo4_tags_test) &&
		BCS_FAILED(rs_halo5_forge) &&
		BCS_FAILED(rs_infinite_flight1_preview) &&
		BCS_FAILED(rs_infinite_flight2_preview) &&
		BCS_FAILED(rs_infinite_release))
	{
		console_write_line("No binary file(s) specified");
		console_write_line("Usage <output directory> <binary ...>");
		return 1;
	}

	int result = 0;

	if (BCS_SUCCEEDED(rs_halo1_guerilla))
	{
		result += blamboozle_run(output_directory, halo1_guerilla_file, _engine_type_halo1, _build_not_set);
	}

	if (BCS_SUCCEEDED(rs_halo2_guerilla))
	{
		result += blamboozle_run(output_directory, halo2_guerilla_file, _engine_type_halo2, _build_not_set, true);
	}

	if (BCS_SUCCEEDED(rs_halo3_guerilla))
	{
		result += blamboozle_run(output_directory, halo3_guerilla_file, _engine_type_halo3, _build_halo3_guerilla, true);
	}

	if (BCS_SUCCEEDED(rs_reach_tags_test_360))
	{
		result += blamboozle_run(output_directory, reach_tags_test_360_file, _engine_type_haloreach, _build_haloreach_tags, true);
	}

	if (BCS_SUCCEEDED(rs_halo4_tags_test))
	{
		result += blamboozle_run(output_directory, halo4_midnight_tags_test, _engine_type_halo4, _build_not_set, true);
	}

	if (BCS_SUCCEEDED(rs_halo5_forge))
	{
		result += blamboozle_run(output_directory, halo5_forge_file, _engine_type_halo5);
	}

	if (BCS_SUCCEEDED(rs_infinite_flight1_preview))
	{
		result += blamboozle_run(output_directory, infinite_flight1_preview_file, _engine_type_infinite, _build_infinite_FLT002INT_199229_21_07_20_0001, true);
	}

	if (BCS_SUCCEEDED(rs_infinite_flight2_preview))
	{
		result += blamboozle_run(output_directory, infinite_flight2_preview_file, _engine_type_infinite, _build_infinite_HIFLTA_202700_21_09_06_0001, true);
	}

	if (BCS_SUCCEEDED(rs_infinite_release))
	{
		result += blamboozle_run(output_directory, infinite_release_file, _engine_type_infinite, _build_infinite_HIREL_209048_21_12_09_1546, true);
	}

	return result;
}

int blamboozle_run(const wchar_t* output_directory, const wchar_t* binary_filepath, e_engine_type engine_type, e_build build, bool skip_hash_check)
{
	if (!skip_hash_check)
	{

		char* binary_data = nullptr;
		unsigned long long binary_data_size = 0;
		if (BCS_FAILED(filesystem_read_file_to_memory(binary_filepath, *reinterpret_cast<void**>(&binary_data), binary_data_size)))
		{
			console_write_line("Failed to open binary file");
			return 1;
		}
		if (binary_data_size == 0)
		{
			console_write_line("Binary file was zero sized");
			return 1;
		}

		e_build build = _build_not_set;

		{
			uint64_t library_file_version;
			wchar_t library_description[2048];
			wchar_t library_product_name[2048];

			ASSERT(BCS_SUCCEEDED(get_library_file_version(binary_filepath, &library_file_version)) || skip_hash_check);
			ASSERT(BCS_SUCCEEDED(get_library_description(binary_filepath, library_description, _countof(library_description))) || skip_hash_check);
			ASSERT(BCS_SUCCEEDED(get_library_product_name(binary_filepath, library_product_name, _countof(library_product_name))) || skip_hash_check);

			uint64_t tool_version = make_tool_version_runtime(library_file_version, library_description, library_product_name);

			if (tool_version == _build_halo1_guerilla)
			{
				build = _build_halo1_guerilla;
				engine_type = _engine_type_halo1;
			}
			else if (tool_version == _build_halo2_guerilla)
			{
				build = _build_halo2_guerilla;
				engine_type = _engine_type_halo2;
			}
		}

		if (build == _build_not_set && !skip_hash_check)
		{
			build = _build_midnight_tag_test_untracked_november_13_2013;
			engine_type = _engine_type_halo4;

			uint64_t hash = xxhash::xxh64(binary_data, binary_data_size);

			if (hash == _build_halo5_forge_1_114_4592_2)
			{
				build = _build_halo5_forge_1_114_4592_2;
				engine_type = _engine_type_halo5;
			}
			if (hash == _build_halo5_forge_1_194_6192_2)
			{
				build = _build_halo5_forge_1_194_6192_2;
				engine_type = _engine_type_halo5;
			}
			if (hash == _build_midnight_tag_test_untracked_november_13_2013)
			{
				build = _build_midnight_tag_test_untracked_november_13_2013;
				engine_type = _engine_type_halo4;
			}
		}

		delete[] binary_data;

		if (engine_type == _engine_type_not_set)
		{
			console_write_line("Unrecognised executable provided");
			return 1;
		}

		const char* build_pretty_name = "unknown";
		get_build_pretty_string(build, &build_pretty_name);

		console_write_line("Found %s build", build_pretty_name);

		const char* engine_type_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_string(engine_type, &engine_type_name)) || skip_hash_check);

	}

	switch (engine_type)
	{
	case _engine_type_halo1:
	{
		c_blamboozle_h1_guerilla h1_guerilla = c_blamboozle_h1_guerilla(output_directory, binary_filepath);
		h1_guerilla.run();
	}
	break;
	case _engine_type_halo2:
	{
		c_blamboozle_h2_guerilla h2_guerilla = c_blamboozle_h2_guerilla(output_directory, binary_filepath);
		h2_guerilla.run();
	}
	break;
	case _engine_type_halo3:
	{
		c_blamboozle_h3_guerilla h3_guerilla = c_blamboozle_h3_guerilla(output_directory, binary_filepath, build);
		h3_guerilla.run();
	}
	break;
	case _engine_type_haloreach:
	{
		c_blamboozle_reach_tags_test_x360 reach_tags_test_x360 = c_blamboozle_reach_tags_test_x360(output_directory, binary_filepath, build);
		reach_tags_test_x360.run();
	}
	break;
	case _engine_type_halo4:
	{
		c_h4_blamboozle h4 = c_h4_blamboozle(output_directory, binary_filepath);
		h4.run();
	}
	break;
	case _engine_type_halo5:
	{
		c_blamboozle_h5_forge h5_forge = c_blamboozle_h5_forge(output_directory, binary_filepath);
		h5_forge.run();
	}
	break;
	case _engine_type_infinite:
	{
		c_blamboozle_infinite infinite = c_blamboozle_infinite(output_directory, binary_filepath, build);
		infinite.run();
	}
	break;
	}

	return 0;
}
