#pragma once

#include <cseries/cseries.h>

/* ---------- classes */

template <typename t_enum, typename t_storage>
class c_enum_no_init
{
	static_assert(__is_enum(t_enum));
	static_assert(__is_convertible_to(t_storage, long));

protected:
	t_storage m_storage;

public:
	template <typename t_type>
	static t_enum cast_to_enum(t_type value)
	{
		return static_cast<t_enum>(value);
	}

	template <typename t_type>
	static t_storage cast_to_storage(t_type value)
	{
		return static_cast<t_storage>(value);
	}

#if __cplusplus > 201703L
	auto operator<=>(t_enum other) const
	{
		return m_storage <=> static_cast<t_storage>(other);
	}
#endif

	operator t_enum() const
	{
		return static_cast<t_enum>(m_storage);
	}
};

template <typename t_enum, typename t_storage>
class c_enum :
	public c_enum_no_init<t_enum, t_storage>
{
public:
	c_enum() = default;
	c_enum(t_enum value) 
	{
		this->m_storage = value;
	}
};
