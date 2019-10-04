#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "math.h"

// TODO 1: Include Box 2 header and library
#include "Box2D/Box2D/Box2D.h"

#ifdef _DEBUG

#pragma comment( lib, "Box2D/libx86/Debug/Box2D.lib" )

#else

#pragma comment( lib, "Box2D/libx86/Release/Box2D.lib" )

#endif

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
	debug = true;
	
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	// TODO 2: Create a private variable for the world
	// - You need to send it a default gravity
	// - You need init the world in the constructor
	// - Remember to destroy the world after using it
	b2Vec2 gravity(0.0f, 10.0f);
	world = new b2World(gravity);

	// TODO 4: Create a a big static circle as "ground"
	Shape(200, 50, 50, false);

	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	// TODO 3: Update the simulation ("step" the world)

	 	world->Step(1.0f / 60.0f, 8, 3);
		
	

	return UPDATE_CONTINUE;
}

void ModulePhysics::Shape(float r, float x, float y, bool d = false)
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(x, y);

	if (d == true)
		groundBodyDef.type = b2_dynamicBody;

	b2Body* groundbody = world->CreateBody(&groundBodyDef);
	b2CircleShape shape;
	shape.m_radius = PIXELS_TO_METERS(r);
	shape.m_type = b2Shape::e_circle;
	
	if (d == true)
	{
		b2FixtureDef frixtureDef;
		frixtureDef.shape = &shape;
		frixtureDef.density = 1.0f;
		frixtureDef.friction = 0.3f;
		groundbody->CreateFixture(&frixtureDef);
	}
	else
		groundbody->CreateFixture(&shape, 0.0f);


}

// 
update_status ModulePhysics::PostUpdate()
{
	// TODO 5: On space bar press, create a circle on mouse position
	// - You need to transform the position / radius

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		Shape(rand()%50+10, PIXELS_TO_METERS(App->input->GetMouseX()),PIXELS_TO_METERS(App->input->GetMouseY()), true);

	if(!debug)
		return UPDATE_CONTINUE;

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	
	for(b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		for(b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch(f->GetType())
			{
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 255, 255, 255);
				}
				break;

				case b2Shape::e_polygon:
				{
					b2PolygonShape* shape = (b2PolygonShape*)f->GetShape();
					int32 con = shape->GetVertexCount();
					b2Vec2 pre = b->GetWorldPoint(shape->GetVertex(0));
					b2Vec2 tam;
					
					for(int32 i=0; i<=con; i++){
					
						tam = b->GetWorldPoint(shape->GetVertex(i));
					if(i>0){
					
						App->renderer->DrawLine(METERS_TO_PIXELS(pre.x), METERS_TO_PIXELS(pre.y), METERS_TO_PIXELS(tam.x), METERS_TO_PIXELS(tam.y), 255, 255, 255);

					}

					}
					
				}
				break;

				// You will have to add more cases to draw boxes, edges, and polygons ...
			}
		}
	}

	return UPDATE_CONTINUE;
}


// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!
	delete world;

	return true;
}

