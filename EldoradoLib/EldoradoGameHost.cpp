#include "eldoradolib-private-pch.h"

void register_eldoradolib()
{

}

GameRuntime EldoradoGameHost::s_eldoradoGameRuntime("eldorado", "eldorado.exe");

EldoradoGameHost::EldoradoGameHost()
	:IOpusGameEngineHost(s_eldoradoGameRuntime)
{
	
}

EldoradoGameHost::~EldoradoGameHost()
{
	
}

void EldoradoGameHost::InitModifications(BuildVersion buildVersion)
{

}

void EldoradoGameHost::DeinitModifications(BuildVersion buildVersion)
{

}
