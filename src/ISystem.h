// MIT License, Copyright (c) 2022 Malik Allen

#ifndef ISYSTEM_H
#define ISYSTEM_H

namespace FiveDeadlyVenoms {

	class ISystem
	{
		ISystem(const ISystem&) = delete;
		ISystem& operator=(const ISystem&) = delete;
		ISystem(ISystem&&) = delete;
		ISystem& operator=(ISystem&&) = delete;

		friend class SystemManager;

		// Unique Identifier Managed by the SystemManager
		uint64_t		m_systemManagerId;

		// Unique Identifier Managed by the SystemManager
		uint64_t		m_systemId;

		// The world this system exists in
		class World*			m_world;

	public:

		explicit ISystem(uint64_t systemID) : m_systemManagerId(0), m_systemId(systemID), m_world(nullptr) {}
		virtual ~ISystem() {}

		virtual void Update(float deltaTime) = 0;

		virtual void OnEntitySignatureChanged( const struct Entity& entity ) = 0;

	protected:

		inline World* GetWorld() const
		{
			return m_world;
		};

	};
	
}




#endif // !ISYSTEM_H



