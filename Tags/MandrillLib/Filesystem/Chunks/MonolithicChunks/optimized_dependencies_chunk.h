#pragma once

class c_optimized_dependencies_chunk : public c_typed_chunk<'opti', false>
{
public:
	c_optimized_dependencies_chunk(c_chunk& parent);
};
