#include "tagvalidate-private-pch.h"

c_gen3_cache_file_validator::c_gen3_cache_file_validator(c_gen3_cache_file& cache_file) :
	cache_file(cache_file),
	engine_type(cache_file.get_engine_type())
{



}

c_gen3_cache_file_validator::~c_gen3_cache_file_validator()
{



}


ImGuiDataType c_gen3_cache_file_validator::field_to_imgui_data_type(blofeld::e_field field_type)
{
	switch (field_type)
	{
	case blofeld::_field_char_enum:return ImGuiDataType_S8;
	case blofeld::_field_enum: return ImGuiDataType_S16;
	case blofeld::_field_long_enum: return ImGuiDataType_S32;
	case blofeld::_field_long_flags: return ImGuiDataType_S32;
	case blofeld::_field_word_flags: return ImGuiDataType_S16;
	case blofeld::_field_byte_flags:return ImGuiDataType_S8;
	case blofeld::_field_char_integer: return ImGuiDataType_S8;
	case blofeld::_field_short_integer: return ImGuiDataType_S16;
	case blofeld::_field_long_integer: return ImGuiDataType_S32;
	case blofeld::_field_int64_integer: return ImGuiDataType_S64;
	case blofeld::_field_angle: return ImGuiDataType_Float;
	case blofeld::_field_real: return ImGuiDataType_Float;
	case blofeld::_field_real_fraction: return ImGuiDataType_Float;
	}
	throw;
}

uint32_t c_gen3_cache_file_validator::get_struct_size(const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t size = 0;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = get_field_size(*current_field);
		size += field_size;
	}

	return size;
}

uint32_t c_gen3_cache_file_validator::get_field_size(const blofeld::s_tag_field& field)
{
	uint32_t field_size = get_blofeld_field_size(field.field_type);
	if (field_size > 0)
	{
		return field_size;
	}
	switch (field.field_type)
	{
	case blofeld::_field_explanation:					return 0;	// empty
	case blofeld::_field_custom:						return 0;	// empty
	case blofeld::_field_terminator:					return 0;	// empty
	case blofeld::_field_pad:							return field.padding;	// dynamic
	case blofeld::_field_useless_pad:					return 0;	// dynamic
	case blofeld::_field_skip:							return field.padding;	// dynamic
	case blofeld::_field_struct:
	{
		uint32_t struct_size = get_struct_size(*field.struct_definition);	// dynamic
		return struct_size;
	}
	case blofeld::_field_array:							return get_struct_size(field.array_definition->struct_definition) * field.array_definition->count;	// dynamic
	}
	throw;
}

uint32_t __log2u(uint32_t index)
{
	uint32_t value = 0;
	while (index >>= 1) ++value;
	return value;
}

uint32_t c_gen3_cache_file_validator::render_tag_struct_definition(int level, char* const data, const blofeld::s_tag_struct_definition& struct_definition, bool is_block, bool render, bool& data_is_valid)
{
	float intent_size = 20.0f;
	uint32_t struct_size = get_struct_size(struct_definition);

	if (render)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, { 0.3f, 0.5f, 1.0f, 1.0f });
		ImGui::Dummy({ level * intent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("STRUCT START>%s [0x%X]", struct_definition.name, struct_size);
		ImGui::PopStyleColor();
	}

	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	char* current_data_position = data;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);

		uint32_t field_size = get_field_size(*current_field);

		
		s_field_validation_result result = {};
		result.field_size = field_size;
		result.string_id_value = nullptr;
		result.tag_reference_instance = nullptr;
		result.float_is_out_of_range = false;
		result.block_is_out_of_range = false;
		result.block_struct_is_valid = true;
		result.level = level + 1;
		if (!data_is_valid) result.validation_state = _validation_state_previously_invalid;
		else
		{
			bool was_tested = true;
			switch (current_field->field_type)
			{
			case blofeld::_field_char_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				char enum_value = *reinterpret_cast<char*>(current_data_position);
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				short enum_value = *reinterpret_cast<short*>(current_data_position);
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_long_enum:
			{
				long enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				long enum_value = *reinterpret_cast<long*>(current_data_position);
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_byte_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				byte enum_value = __log2u(*reinterpret_cast<byte*>(current_data_position));
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_word_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				word enum_value = __log2u(*reinterpret_cast<word*>(current_data_position));
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_real:
			case blofeld::_field_angle:
			case blofeld::_field_real_fraction:
			{
				float float_value = *reinterpret_cast<float*>(current_data_position);
				data_is_valid &= !isnan(float_value);
				result.float_is_out_of_range |= fabsf(float_value) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_point_2d:
			case blofeld::_field_real_vector_2d:
			case blofeld::_field_angle_bounds:
			case blofeld::_field_real_bounds:
			case blofeld::_field_real_fraction_bounds:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				data_is_valid &= !isnan(float_value0);
				data_is_valid &= !isnan(float_value1);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_point_3d:
			case blofeld::_field_real_vector_3d:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				float float_value2 = reinterpret_cast<float*>(current_data_position)[2];
				data_is_valid &= !isnan(float_value0);
				data_is_valid &= !isnan(float_value1);
				data_is_valid &= !isnan(float_value2);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value2) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_real_quaternion:
			{
				float float_value0 = reinterpret_cast<float*>(current_data_position)[0];
				float float_value1 = reinterpret_cast<float*>(current_data_position)[1];
				float float_value2 = reinterpret_cast<float*>(current_data_position)[2];
				float float_value3 = reinterpret_cast<float*>(current_data_position)[4];
				data_is_valid &= !isnan(float_value0);
				data_is_valid &= !isnan(float_value1);
				data_is_valid &= !isnan(float_value2);
				data_is_valid &= !isnan(float_value3);
				result.float_is_out_of_range |= fabsf(float_value0) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value1) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value2) > float(0xFFFFFFFu);
				result.float_is_out_of_range |= fabsf(float_value3) > float(0xFFFFFFFu);
				break;
			}
			case blofeld::_field_long_flags:
			{
				uint32_t enum_max = current_field->string_list_definition ? current_field->string_list_definition->count : 0;
				unsigned long enum_value = __log2u(*reinterpret_cast<unsigned long*>(current_data_position));
				data_is_valid &= enum_value < enum_max;
				break;
			}
			case blofeld::_field_string_id:
			{
				string_id value = *reinterpret_cast<string_id*>(current_data_position);
				result.string_id_value = cache_file.get_string_id(value, nullptr);
				data_is_valid &= result.string_id_value != nullptr;
				break;
			}
			case blofeld::_field_pad:
				for (uint32_t i = 0; i < current_field->padding; i++)
				{
					data_is_valid &= current_data_position[i] == 0;
				}
				break;
			case blofeld::_field_tag_reference:
			{
				s_tag_reference& tag_reference = *reinterpret_cast<s_tag_reference*>(current_data_position);

				if (tag_reference.group_tag == UINT32_MAX)
				{
					data_is_valid &= tag_reference.name_length == 0;
					data_is_valid &= tag_reference.index == UINT16_MAX;
					data_is_valid &= tag_reference.datum == UINT16_MAX;
				}
				else
				{
					const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(tag_reference.group_tag);
					data_is_valid = known_legacy_tag_group_name != nullptr;
				}
				if (data_is_valid && tag_reference.index != UINT16_MAX)
				{
					result.tag_reference_instance = cache_file.get_tag_interface(tag_reference.index);
					data_is_valid &= result.tag_reference_instance != nullptr;
				}
				break;
			}
			case blofeld::_field_data:
			{
				s_tag_data& tag_data = *reinterpret_cast<s_tag_data*>(current_data_position);

				data_is_valid &= tag_data.stream_flags == 0;
				data_is_valid &= tag_data.stream_offset == 0;
				data_is_valid &= tag_data.definition == 0;
				if (tag_data.size > 0)
				{
					char* data_address = cache_file.get_data_with_page_offset(tag_data.address);
					data_is_valid &= cache_file.is_valid_data_address(data_address);
				}
				break;
			}
			case blofeld::_field_block:
			{
				s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(current_data_position);

				bool is_valid = true;
				data_is_valid &= tag_block.definition_address == 0;
				if (tag_block.count == 0)
				{
					data_is_valid &= tag_block.address == 0;
				}
				else
				{
					char* data_address_old = cache_file.get_data_with_page_offset(tag_block.address);
					char* data_address = cache_file.get_tag_block_data(tag_block);
					data_is_valid &= cache_file.is_valid_data_address(data_address);
					data_is_valid &= cache_file.is_valid_data_address(data_address);

					if (data_is_valid)
					{
						result.block_is_out_of_range = tag_block.count > current_field->block_definition->max_count;

						char* block_data_position = data_address;
						for (uint32_t tag_block_index = 0; tag_block_index < tag_block.count; tag_block_index++)
						{
							uint32_t bytes_traversed = render_tag_struct_definition(level + 2, block_data_position, current_field->block_definition->struct_definition, true, false, result.block_struct_is_valid);
							block_data_position += bytes_traversed;
						}
					}
				}
				break;
			}
			case blofeld::_field_struct:
			{
				render_tag_struct_definition(level + 2, current_data_position, *current_field->struct_definition, false, render, data_is_valid);
				break;
			}
			case blofeld::_field_array:
			{
				char* array_data_position = current_data_position;
				for (uint32_t i = 0; i < current_field->array_definition->count; i++)
				{
					uint32_t bytes_traversed = render_tag_struct_definition(level + 2, array_data_position, *current_field->struct_definition, false, render, data_is_valid);
					array_data_position += bytes_traversed;
				}
				break;
			}
			default:
			{
				was_tested = false;
				break;
			}
			}

			if (!was_tested) result.validation_state = _validation_state_unknown;
			else if (!data_is_valid) result.validation_state = _validation_state_invalid;
			else if (result.float_is_out_of_range) result.validation_state = _validation_state_warning;
			else if (result.block_is_out_of_range) result.validation_state = _validation_state_warning;
			else if (!result.block_struct_is_valid) result.validation_state = _validation_state_warning;
			else if (is_block) result.validation_state = _validation_state_block_valid;
			else result.validation_state = _validation_state_valid;
		}

		if (render)
		{
			switch (current_field->field_type)
			{
			case blofeld::_field_custom:
			//case blofeld::_field_explanation:
				break; // skip rendering custom fields
			default:
				field_render_callback(current_data_position, *current_field, &result, field_type_render_callbacks[current_field->field_type]);
			}

			switch (current_field->field_type)
			{
			case blofeld::_field_block:
			{
				s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(current_data_position);

				if (data_is_valid)
				{
					bool is_struct_valid = true;
					char* block_data_position_old = cache_file.get_data_with_page_offset(tag_block.address);
					char* block_data_position = cache_file.get_tag_block_data(tag_block);
					for (uint32_t tag_block_index = 0; tag_block_index < tag_block.count && is_struct_valid; tag_block_index++)
					{
						uint32_t bytes_traversed = render_tag_struct_definition(level + 2, block_data_position, current_field->block_definition->struct_definition, true, render, is_struct_valid);
						block_data_position += bytes_traversed;
					}
				}
				break;
			}
			}
		}

		current_data_position += field_size;
		bytes_traversed += field_size;
	}

	if (render)
	{
		ImGui::PushStyleColor(ImGuiCol_Text, { 0.3f, 0.5f, 1.0f, 1.0f });
		ImGui::Dummy({ level * intent_size, 0.0f }); ImGui::SameLine(); ImGui::Text("STRUCT END>%s [0x%X]", struct_definition.name, struct_size);
		ImGui::PopStyleColor();
	}

	return bytes_traversed;
}

uint32_t c_gen3_cache_file_validator::validate_tag_group(char* data, const blofeld::s_tag_group& group)
{
	//if (group.parent_group_tag)
	//{
	//	ASSERT(group.parent_tag_group != nullptr);
	//	uint32_t parent_bytes_traversed = render_tag_group(data, *group.parent_tag_group);
	//	data += parent_bytes_traversed;
	//}

	bool data_is_valid = true;
	uint32_t bytes_traversed = render_tag_struct_definition(0, data, group.block_definition.struct_definition, false, true, data_is_valid);
	return bytes_traversed;
}

void c_gen3_cache_file_validator::validate_tag_instance(c_gen3_tag_interface& tag_interface)
{
	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();
	char* data = tag_interface.get_data();

	validate_tag_group(data, *group);
}
