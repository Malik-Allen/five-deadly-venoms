# Five Deadly Venoms

## C++ Entity Component System

### Quick Start

`Entity`, `Component`, `System` are all instantiated and managed through a `World` object.

All user-defined Components and Systems must contain the following static member:

`static constexpr uint32_t ID = GENERATE_ID( "ExampleClassName" );`

The `ID` allows the ECS to generate a unique identifier for the given component or system at compile-time.

This `ID` must be passed as a paramter to the parent constructor call in classes derived from `System` and `Component`, see example below:

```
class FooComponent : public FiveDeadlyVenoms::Component {
public:
	static constexpr uint32_t ID = GENERATE_ID( "FooComponent" );

	FooComponent(): 
        Component(ID) 
    {};

	~FooComponent() = default;
};
```

Once instantiated the `World` object is responsible for creating entities and adding/removing components from entities at run-time.

`Parser<...>` can be used on a `World` object to obtain all entities with the matching `Component` signature, see example below:

`FiveDeadlyVenoms::Parser<AudioComponent, PhysicsComponent>( WorldObject );`


### Systems

All Systems are defined by its `Component Signature`, the components that need to be present on the Entity to be updated within this System, see example below:

```
class FooSystem : public FiveDeadlyVenoms::System<FooComponent, FoobarComponent>
{
public:
	static constexpr uint64_t ID = GENERATE_ID("FooSystem");

	FooSystem(): 
        System(ID) 
    {}
	~FooSystem() = default;
};
```
All user-defined systems must be registered with a `World` object at run-time.

### Features

Make Components private in System, GetComponents(); and a templated Get<> call to get specific component

Only allow for unique Components onto Entities