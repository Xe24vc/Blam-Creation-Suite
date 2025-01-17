#pragma once

#include "tag_file_high_level_transplant.h"

#include "tag_file_string_debugger.h"
#include "single_tag_file_header.h"
#include "single_tag_file_layout_reader.h"
#include "single_tag_file_reader.h"
#include "high_level_tag_file_writer.h"

#include "system_global_unique_identifier.h"

#include "Chunks\chunk.h"
#include "Chunks\typed_chunk.h"
#include "Chunks\tag_header_chunk.h"
#include "Chunks\monolithic_tag_backend_chunk.h"

#include "Chunks\LayoutChunks\string_data_chunk.h"
#include "Chunks\LayoutChunks\string_offsets_chunk.h"
#include "Chunks\LayoutChunks\string_lists_chunk.h"

#include "Chunks\LayoutChunks\tag_group_layout_chunk.h"
#include "Chunks\LayoutChunks\custom_block_index_search_names_chunk.h"
#include "Chunks\LayoutChunks\data_definition_name_chunk.h"
#include "Chunks\LayoutChunks\array_definitions_chunk.h"
#include "Chunks\LayoutChunks\field_types_chunk.h"
#include "Chunks\LayoutChunks\fields_chunk.h"
#include "Chunks\LayoutChunks\block_definitions_chunk.h"
#include "Chunks\LayoutChunks\resource_definitions_chunk.h"
#include "Chunks\LayoutChunks\interop_definitions_chunk.h"
#include "Chunks\LayoutChunks\structure_definitions_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_prechunk_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_preinterop_chunk.h"
#include "Chunks\LayoutChunks\tag_layout_v3_chunk.h"

#include "Chunks\TagChunks\binary_data_chunk.h"
#include "Chunks\TagChunks\tag_string_id_chunk.h"
#include "Chunks\TagChunks\tag_data_chunk.h"
#include "Chunks\TagChunks\tag_reference_chunk.h"
#include "Chunks\TagChunks\tag_struct_chunk.h"
#include "Chunks\TagChunks\tag_block_chunk.h"
#include "Chunks\TagChunks\tag_resource_null_chunk.h"
#include "Chunks\TagChunks\tag_resource_exploded_chunk.h"
#include "Chunks\TagChunks\tag_resource_data_chunk.h"
#include "Chunks\TagChunks\tag_resource_xsynced_chunk.h"

#include "Chunks\MonolithicChunks\monolithic_tag_file_index_chunk.h"
#include "Chunks\MonolithicChunks\tag_file_index_chunk.h"
#include "Chunks\MonolithicChunks\tag_heap_chunk.h"
#include "Chunks\MonolithicChunks\cache_heap_chunk.h"
#include "Chunks\MonolithicChunks\tag_file_blocks_chunk.h"
#include "Chunks\MonolithicChunks\build_identifier_chunk.h"
#include "Chunks\MonolithicChunks\monolithic_index_chunk.h"
#include "Chunks\MonolithicChunks\tag_file_persistent_heap_chunk.h"
#include "Chunks\MonolithicChunks\tag_file_heap_partition_config_chunk.h"
#include "Chunks\MonolithicChunks\partitioned_persistent_heap_backend_chunk.h"
#include "Chunks\MonolithicChunks\partition_list_chunk.h"
#include "Chunks\MonolithicChunks\partition_chunk.h"
#include "Chunks\MonolithicChunks\partitioned_heap_entry_list_chunk.h"
#include "Chunks\MonolithicChunks\tag_dependency_index_loader_chunk.h"
#include "Chunks\MonolithicChunks\tag_dependency_chunk.h"
#include "Chunks\MonolithicChunks\exploded_dependencies_chunk.h"
#include "Chunks\MonolithicChunks\optimized_dependencies_chunk.h"
#include "Chunks\MonolithicChunks\monolithic_tag_file_layout_registry_chunk.h"
