#include "tagdefinitions-private-pch.h"

using namespace blofeld;

unsigned long blofeld::get_blofeld_field_size(e_platform_type platform_type, e_field field)
{
	if (field > _field_type_non_standard)
	{
		return 0;
	}
	switch (field)
	{
	case _field_string:							return sizeof(::c_static_string<32>);
	case _field_long_string:					return sizeof(::c_static_string<256>);
	case _field_string_id:						return sizeof(string_id);
	case _field_old_string_id:					return sizeof(::c_old_string_id);
	case _field_char_integer:					return sizeof(char);
	case _field_short_integer:					return sizeof(short);
	case _field_long_integer:					return sizeof(long);
	case _field_int64_integer:					return sizeof(long long);
	case _field_angle:							return sizeof(angle);
	case _field_tag:							return sizeof(tag);
	case _field_char_enum:						return sizeof(char);
	case _field_enum:							return sizeof(short);
	case _field_long_enum:						return sizeof(long);
	case _field_long_flags:						return sizeof(long);
	case _field_word_flags:						return sizeof(word);
	case _field_byte_flags:						return sizeof(byte);
	case _field_point_2d:						return sizeof(::s_point2d);
	case _field_rectangle_2d:					return sizeof(::s_rectangle2d);
	case _field_rgb_color:						return sizeof(::pixel32);
	case _field_argb_color:						return sizeof(::pixel32);
	case _field_real:							return sizeof(::real);
	case _field_real_fraction:					return sizeof(::real_fraction);
	case _field_real_point_2d:					return sizeof(::real_point2d);
	case _field_real_point_3d:					return sizeof(::real_point3d);
	case _field_real_vector_2d:					return sizeof(::real_vector2d);
	case _field_real_vector_3d:					return sizeof(::real_vector3d);
	case _field_real_quaternion:				return sizeof(::real_quaternion);
	case _field_real_euler_angles_2d:			return sizeof(::real_euler_angles2d);
	case _field_real_euler_angles_3d:			return sizeof(::real_euler_angles3d);
	case _field_real_plane_2d:					return sizeof(::real_plane2d);
	case _field_real_plane_3d:					return sizeof(::real_plane3d);
	case _field_real_rgb_color:					return sizeof(::rgb_color);
	case _field_real_argb_color:				return sizeof(::argb_color);
	case _field_real_hsv_color:					return sizeof(::real_hsv_color);
	case _field_real_ahsv_color:				return sizeof(::real_ahsv_color);
	case _field_short_bounds:					return sizeof(::short_bounds);
	case _field_angle_bounds:					return sizeof(::angle_bounds);
	case _field_real_bounds:					return sizeof(::real_bounds);
	case _field_real_fraction_bounds:			return sizeof(::real_fraction_bounds);
	case _field_tag_reference:					return sizeof(::s_tag_reference);
	case _field_block:							return sizeof(::s_tag_block);
	case _field_long_block_flags:				return sizeof(long);
	case _field_word_block_flags:				return sizeof(word);
	case _field_byte_block_flags:				return sizeof(byte);
	case _field_char_block_index:				return sizeof(char);
	case _field_custom_char_block_index:		return sizeof(char);
	case _field_short_block_index:				return sizeof(short);
	case _field_custom_short_block_index:		return sizeof(short);
	case _field_long_block_index:				return sizeof(long);
	case _field_custom_long_block_index:		return sizeof(long);
	case _field_data:							return sizeof(::s_tag_data);
	case _field_vertex_buffer:					return sizeof(::s_tag_d3d_vertex_buffer);
	case _field_pad:							return 0;	// dynamic
	case _field_useless_pad:					return 0;	// dynamic
	case _field_skip:							return 0;	// dynamic
	case _field_non_cache_runtime_value:		return 0;	// empty
	case _field_explanation:					return 0;	// empty
	case _field_custom:							return 0;	// empty
	case _field_struct:							return 0;	// dynamic
	case _field_array:							return 0;	// dynamic
	case _field_pageable:						return sizeof(::s_tag_resource);
	case _field_api_interop:					return sizeof(::s_tag_interop);
	case _field_terminator:						return 0;	// empty
	case _field_byte_integer:					return sizeof(byte);
	case _field_word_integer:					return sizeof(word);
	case _field_dword_integer:					return sizeof(dword);
	case _field_qword_integer:					return sizeof(qword);
	case _field_embedded_tag:					return sizeof(::s_tag_reference);
	case _field_data_path:						return sizeof(::c_static_string<256>);
	case _field_pointer:
	{
		unsigned long pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(platform_type, &pointer_size)));
		return pointer_size;
	};
	case _field_half:							return sizeof(uint16_t);
	default: FATAL_ERROR("unknown field type");
	}
	return 0;
}

unsigned long blofeld::get_blofeld_field_size(const s_tag_field& field, s_engine_platform_build engine_platform_build)
{
	switch (field.field_type)
	{
	case _field_pad:							return field.padding;
	case _field_useless_pad:					return 0;
	case _field_skip:							return field.length;
	case _field_struct:
	{
		unsigned long structure_size = blofeld::calculate_struct_size(engine_platform_build, *field.struct_definition);
		return structure_size;
	}
	case _field_array:
	{
		unsigned long structure_size = blofeld::calculate_struct_size(engine_platform_build, field.array_definition->struct_definition);
		unsigned long array_element_count = field.array_definition->count(engine_platform_build);
		unsigned long array_size = structure_size * array_element_count;
		return array_size;
	}
	default: return get_blofeld_field_size(engine_platform_build.platform_type, field.field_type);
	}
}

BCS_DEBUG_API BCS_RESULT blofeld::field_to_tag_field_type(e_field field, const char*& tag_field_type)
{
#define FIELD_TO_TAG_FIELD_TYPE(_field, _tag_field_type) if(_field == field) { tag_field_type = _tag_field_type; return BCS_S_OK; }

	FIELD_TO_TAG_FIELD_TYPE(_field_string, "string");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_string, "long string");
	FIELD_TO_TAG_FIELD_TYPE(_field_string_id, "string id");
	FIELD_TO_TAG_FIELD_TYPE(_field_old_string_id, "old string id");
	FIELD_TO_TAG_FIELD_TYPE(_field_char_integer, "char integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_short_integer, "short integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_integer, "long integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_int64_integer, "int64 integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_angle, "angle");
	FIELD_TO_TAG_FIELD_TYPE(_field_tag, "tag");
	FIELD_TO_TAG_FIELD_TYPE(_field_char_enum, "char enum");
	FIELD_TO_TAG_FIELD_TYPE(_field_enum, "short enum");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_enum, "long enum");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_flags, "long flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_word_flags, "word flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_byte_flags, "byte flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_point_2d, "point 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_rectangle_2d, "rectangle 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_rgb_color, "rgb color");
	FIELD_TO_TAG_FIELD_TYPE(_field_argb_color, "argb color");
	FIELD_TO_TAG_FIELD_TYPE(_field_real, "real");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_fraction, "real fraction");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_point_2d, "real point 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_point_3d, "real point 3d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_vector_2d, "real vector 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_vector_3d, "real vector 3d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_quaternion, "real quaternion");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_euler_angles_2d, "real euler angles 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_euler_angles_3d, "real euler angles 3d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_plane_2d, "real plane 2d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_plane_3d, "real plane 3d");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_rgb_color, "real rgb color");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_argb_color, "real argb color");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_hsv_color, "real hsv color");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_ahsv_color, "real ahsv color");
	FIELD_TO_TAG_FIELD_TYPE(_field_short_bounds, "short integer bounds");
	FIELD_TO_TAG_FIELD_TYPE(_field_angle_bounds, "angle bounds");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_bounds, "real bounds");
	FIELD_TO_TAG_FIELD_TYPE(_field_real_fraction_bounds, "fraction bounds");
	FIELD_TO_TAG_FIELD_TYPE(_field_tag_reference, "tag reference");
	FIELD_TO_TAG_FIELD_TYPE(_field_block, "block");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_block_flags, "long block flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_word_block_flags, "word block flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_byte_block_flags, "byte block flags");
	FIELD_TO_TAG_FIELD_TYPE(_field_char_block_index, "char block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_custom_char_block_index, "custom char block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_short_block_index, "short block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_custom_short_block_index, "custom short block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_long_block_index, "long block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_custom_long_block_index, "custom long block index");
	FIELD_TO_TAG_FIELD_TYPE(_field_data, "data");
	FIELD_TO_TAG_FIELD_TYPE(_field_vertex_buffer, "vertex buffer");
	FIELD_TO_TAG_FIELD_TYPE(_field_pad, "pad");
	FIELD_TO_TAG_FIELD_TYPE(_field_useless_pad, "useless pad");
	FIELD_TO_TAG_FIELD_TYPE(_field_skip, "skip");
	FIELD_TO_TAG_FIELD_TYPE(_field_non_cache_runtime_value, "non-cache runtime value");
	FIELD_TO_TAG_FIELD_TYPE(_field_explanation, "explanation");
	FIELD_TO_TAG_FIELD_TYPE(_field_custom, "custom");
	FIELD_TO_TAG_FIELD_TYPE(_field_struct, "struct");
	FIELD_TO_TAG_FIELD_TYPE(_field_array, "array");
	FIELD_TO_TAG_FIELD_TYPE(_field_pageable, "pageable resource");
	FIELD_TO_TAG_FIELD_TYPE(_field_api_interop, "api interop");
	FIELD_TO_TAG_FIELD_TYPE(_field_terminator, "terminator X");
	FIELD_TO_TAG_FIELD_TYPE(_field_byte_integer, "byte integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_word_integer, "word integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_dword_integer, "dword integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_qword_integer, "qword integer");
	FIELD_TO_TAG_FIELD_TYPE(_field_data_path, "data path"); // H5F/INF
	FIELD_TO_TAG_FIELD_TYPE(_field_embedded_tag, "embedded tag"); // H5F/INF
	FIELD_TO_TAG_FIELD_TYPE(_field_pointer, "pointer"); // #NONSTANDARD
	FIELD_TO_TAG_FIELD_TYPE(_field_half, "half"); // #NONSTANDARD

	return BCS_E_NOT_FOUND;
#undef FIELD_TO_TAG_FIELD_TYPE
}

BCS_DEBUG_API BCS_RESULT blofeld::tag_field_type_to_field(const char* tag_field_type, e_field& field)
{
	for (underlying(e_field) field_type = 0; field_type < _field_type_non_standard_custom_type; field_type++)
	{
		e_field current_field_type = static_cast<e_field>(field_type);
		const char* current_tag_field_type;
		if (BCS_SUCCEEDED(::field_to_tag_field_type(current_field_type, current_tag_field_type)))
		{
			if (strcmp(tag_field_type, current_tag_field_type) == 0)
			{
				field = current_field_type;
				return BCS_S_OK;
			}
		}
	}
	return BCS_E_NOT_FOUND;
}
