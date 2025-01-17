#pragma once

namespace blofeld
{



	constexpr unsigned long INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG = 'igpd';
	extern s_tag_group incident_global_properties_definition_group; // incident_global_properties_definition_block

	constexpr unsigned long INCIDENT_GLOBALS_DEFINITION_TAG = 'ingd';
	extern s_tag_group incident_globals_definition_group; // incident_globals_definition_block
	extern s_tag_block_definition incident_globals_definition_block;
	extern s_tag_struct_definition incident_globals_definition_block_struct_definition; // incident_globals_definition_block

	constexpr unsigned long SUPPRESSEDINCIDENT_TAG = 'sigd';
	extern s_tag_group SuppressedIncident_group; // SuppressedIncident_block

	extern s_tag_block_definition incident_global_properties_incident_definitions_block;
	extern s_tag_struct_definition incident_global_properties_incident_definitions_block_struct_definition;

	extern s_tag_block_definition incident_global_properties_definition_block;
	extern s_tag_block_definition SuppressedIncident_block;
	extern s_tag_block_definition incident_definition_block;
	extern s_tag_struct_definition incident_definition_block_struct_definition; // incident_definition_block
	extern s_tag_block_definition suppressed_incident_block;
	extern s_tag_struct_definition suppressed_incident_block_struct_definition; // suppressed_incident_block
	extern s_tag_block_definition SuppressedIncidentBlockReferenceDefinition_block;
	extern s_tag_struct_definition SuppressedIncidentBlockReferenceDefinition_block_struct_definition; // SuppressedIncidentBlockReferenceDefinition_block
	extern s_tag_block_definition specialized_incident_block;
	extern s_tag_struct_definition specialized_incident_block_struct_definition; // specialized_incident_block
	extern s_tag_block_definition specialized_incident_kill_implement_block;
	extern s_tag_struct_definition specialized_incident_kill_implement_block_struct_definition; // specialized_incident_kill_implement_block
	extern s_tag_block_definition specialized_incident_object_properties_block;
	extern s_tag_struct_definition specialized_incident_object_properties_block_struct_definition; // specialized_incident_object_properties_block
	extern s_tag_block_definition specialized_incident_object_riding_in_vehicle_properties_block;
	extern s_tag_struct_definition specialized_incident_object_riding_in_vehicle_properties_block_struct_definition; // specialized_incident_object_riding_in_vehicle_properties_block
	extern s_tag_block_definition specialized_incident_special_kill_type_block;
	extern s_tag_struct_definition specialized_incident_special_kill_type_block_struct_definition; // specialized_incident_special_kill_type_block
	extern s_tag_block_definition specializedIncidentGameOverBlock_block;
	extern s_tag_struct_definition specializedIncidentGameOverBlock_block_struct_definition; // specializedIncidentGameOverBlock_block
	extern s_tag_block_definition specializedIncidentRandomOrdnanceBlock_block;
	extern s_tag_struct_definition specializedIncidentRandomOrdnanceBlock_block_struct_definition; // specializedIncidentRandomOrdnanceBlock_block
	extern s_tag_block_definition specializedIncidentCustomDataFilterBlock_block;
	extern s_tag_struct_definition specializedIncidentCustomDataFilterBlock_block_struct_definition; // specializedIncidentCustomDataFilterBlock_block
	extern s_tag_block_definition specializedIncidentDistanceFilterBlock_block;
	extern s_tag_struct_definition specializedIncidentDistanceFilterBlock_block_struct_definition; // specializedIncidentDistanceFilterBlock_block
	extern s_tag_block_definition incident_accumulator_block;
	extern s_tag_struct_definition incident_accumulator_block_struct_definition; // incident_accumulator_block
	extern s_tag_block_definition incident_accumulator_child_incident_block;
	extern s_tag_struct_definition incident_accumulator_child_incident_block_struct_definition; // incident_accumulator_child_incident_block
	extern s_tag_block_definition incident_sum_accumulator_block;
	extern s_tag_struct_definition incident_sum_accumulator_block_struct_definition; // incident_sum_accumulator_block
	extern s_tag_block_definition incident_sum_accumulator_child_incident_block;
	extern s_tag_struct_definition incident_sum_accumulator_child_incident_block_struct_definition; // incident_sum_accumulator_child_incident_block

	extern s_tag_struct_definition incident_global_properties_definition_struct_definition; // tag group
	extern s_tag_struct_definition SuppressedIncident_struct_definition; // tag group

	extern s_string_list_definition numeric_comparison_flags;
	extern s_string_list_definition suppressed_incident_flags;
	extern s_string_list_definition incident_definition_flags;
	extern s_string_list_definition specialized_incident_kill_bucket_flags;
	extern s_string_list_definition specializedIncidentGameOverFlags;
	extern s_string_list_definition specialized_incident_special_kill_type_enum;
	extern s_string_list_definition incident_accumulator_reset_enum;
	extern s_string_list_definition incident_accumulator_aggregation_method_enum;

	extern s_tag_reference_definition SuppressedIncidentGroupReference;



} // namespace blofeld

