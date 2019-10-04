#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePhysics.h"
#include "math.h"

#include "Box2D/Box2D/Box2D.h"

#ifdef _DEBUG
#pragma comment( lib, "Box2D/libx86/Debug/Box2D.lib" )
#else
#pragma comment( lib, "Box2D/libx86/Release/Box2D.lib" )
#endif

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	world = NULL;
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	world = new b2World(b2Vec2(GRAVITY_X, -GRAVITY_Y));

	// big static circle as "ground" in the middle of the screen
	int x = SCREEN_WIDTH / 2;
	int y = SCREEN_HEIGHT / 1.5f;
	int diameter = SCREEN_WIDTH / 2;

	b2BodyDef body;
	body.type = b2_staticBody;
	body.position.Set(PIXEL_TO_METERS(x), PIXEL_TO_METERS(y));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = PIXEL_TO_METERS(diameter) * 0.5f;

	b2FixtureDef fixture;
	fixture.shape = &shape;
	b->CreateFixture(&fixture);

	return true;
}

// 
update_status ModulePhysics::PreUpdate()
{
	world->Step(1.0f / 60.0f, 6, 2);

	return UPDATE_CONTINUE;
}

// 
update_status ModulePhysics::PostUpdate()
{
	// On space bar press, create a circle on mouse position
	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		b2BodyDef body;
		body.type = b2_dynamicBody;
		float radius = PIXEL_TO_METERS(25);
		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* b = world->CreateBody(&body);

		b2CircleShape shape;
		shape.m_radius = radius;
		b2FixtureDef fixture;
		fixture.shape = &shape;

		b->CreateFixture(&fixture);
	}

	if(App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		// TODO 1: When pressing 2, create a box on the mouse position

		b2BodyDef body;
		body.type = b2_dynamicBody;
		float width = PIXEL_TO_METERS(15);
		float height = PIXEL_TO_METERS(15);
		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));

		b2Body* b = world->CreateBody(&body);

		b2PolygonShape rectangle;
		rectangle.SetAsBox(width, height);
		b2FixtureDef fixture;
		// TODO 2: To have the box behave normally, set fixture's density to 1.0f
		fixture.density = 1.0f;
		fixture.shape = &rectangle;

		b->CreateFixture(&fixture);

		
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// TODO 3: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!
		b2BodyDef chain1;
		chain1.type = b2_dynamicBody;
		chain1.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));
		b2Body* b2 = world->CreateBody(&chain1);
		
		b2Vec2 points[12];
		points[0].Set(PIXEL_TO_METERS(-38), PIXEL_TO_METERS(80));
		points[1].Set(PIXEL_TO_METERS(-44), PIXEL_TO_METERS(-54));
		points[2].Set(PIXEL_TO_METERS(-16), PIXEL_TO_METERS(-60));
		points[3].Set(PIXEL_TO_METERS(-16), PIXEL_TO_METERS(17));
		points[4].Set(PIXEL_TO_METERS(19), PIXEL_TO_METERS(-19));
		points[5].Set(PIXEL_TO_METERS(19), PIXEL_TO_METERS(-79));
		points[6].Set(PIXEL_TO_METERS(61), PIXEL_TO_METERS(-77));
		points[7].Set(PIXEL_TO_METERS(57), PIXEL_TO_METERS(73));
		points[8].Set(PIXEL_TO_METERS(17), PIXEL_TO_METERS(78));
		points[9].Set(PIXEL_TO_METERS(20), PIXEL_TO_METERS(16));
		points[10].Set(PIXEL_TO_METERS(-25), PIXEL_TO_METERS(13));
		points[11].Set(PIXEL_TO_METERS(-9), PIXEL_TO_METERS(72));

		b2ChainShape chain;

		chain.CreateLoop(points, 12);

		b2FixtureDef fixture;
		fixture.shape = &chain;
		b2->CreateFixture(&fixture);

	

	}

	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
	{
		// TODO 3: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!
		b2BodyDef chain2;
		chain2.type = b2_dynamicBody;
		chain2.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));
		b2Body* b3 = world->CreateBody(&chain2);

		b2Vec2 points[33];
		points[0].Set(PIXEL_TO_METERS(41), PIXEL_TO_METERS(39));
		points[1].Set(PIXEL_TO_METERS(11), PIXEL_TO_METERS(34));
		points[2].Set(PIXEL_TO_METERS(28), PIXEL_TO_METERS(63));
		points[3].Set(PIXEL_TO_METERS(0), PIXEL_TO_METERS(75));
		points[4].Set(PIXEL_TO_METERS(28), PIXEL_TO_METERS(90));
		points[5].Set(PIXEL_TO_METERS(8), PIXEL_TO_METERS(103));
		points[6].Set(PIXEL_TO_METERS(29), PIXEL_TO_METERS(115));
		points[7].Set(PIXEL_TO_METERS(20), PIXEL_TO_METERS(126));
		points[8].Set(PIXEL_TO_METERS(39), PIXEL_TO_METERS(126));
		points[9].Set(PIXEL_TO_METERS(31), PIXEL_TO_METERS(137));
		points[10].Set(PIXEL_TO_METERS(47), PIXEL_TO_METERS(135));
		points[11].Set(PIXEL_TO_METERS(55), PIXEL_TO_METERS(146));
		points[12].Set(PIXEL_TO_METERS(70), PIXEL_TO_METERS(150));
		points[13].Set(PIXEL_TO_METERS(85), PIXEL_TO_METERS(149));
		points[14].Set(PIXEL_TO_METERS(94), PIXEL_TO_METERS(140));
		points[15].Set(PIXEL_TO_METERS(101), PIXEL_TO_METERS(126));
		points[16].Set(PIXEL_TO_METERS(109), PIXEL_TO_METERS(123));
		points[17].Set(PIXEL_TO_METERS(103), PIXEL_TO_METERS(117));
		points[18].Set(PIXEL_TO_METERS(102), PIXEL_TO_METERS(106));
		points[19].Set(PIXEL_TO_METERS(110), PIXEL_TO_METERS(100));
		points[20].Set(PIXEL_TO_METERS(107), PIXEL_TO_METERS(94));
		points[21].Set(PIXEL_TO_METERS(111), PIXEL_TO_METERS(80));
		points[22].Set(PIXEL_TO_METERS(111), PIXEL_TO_METERS(74));
		points[23].Set(PIXEL_TO_METERS(118), PIXEL_TO_METERS(65));
		points[24].Set(PIXEL_TO_METERS(106), PIXEL_TO_METERS(61));
		points[25].Set(PIXEL_TO_METERS(112), PIXEL_TO_METERS(29));
		points[26].Set(PIXEL_TO_METERS(95), PIXEL_TO_METERS(39));
		points[27].Set(PIXEL_TO_METERS(96), PIXEL_TO_METERS(17));
		points[28].Set(PIXEL_TO_METERS(89), PIXEL_TO_METERS(5));
		points[29].Set(PIXEL_TO_METERS(81), PIXEL_TO_METERS(17));
		points[30].Set(PIXEL_TO_METERS(74), PIXEL_TO_METERS(32));
		points[31].Set(PIXEL_TO_METERS(41), PIXEL_TO_METERS(-2));
		points[32].Set(PIXEL_TO_METERS(41), PIXEL_TO_METERS(35));


		b2ChainShape chain;

		chain.CreateLoop(points, 33);

		b2FixtureDef fixture2;
		fixture2.shape = &chain;
		b3->CreateFixture(&fixture2);



	}
		
	if (App->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN)
	{
		
		b2BodyDef body3;
		body3.type = b2_dynamicBody;
		
		int rick_head[66] = {
			
			41, 39,
			11, 34,
			28, 63,
			0, 75,
			28, 90,
			8, 103,
			29, 115,
			20, 126,
			39, 126,
			31, 137,
			47, 135,
			55, 146,
			70, 150,
			85, 149,
			94, 140,
			101, 126,
			109, 123,
			103, 117,
			102, 106,
			110, 100,
			107, 94,
			111, 80,
			111, 74,
			118, 65,
			106, 61,
			112, 29,
			95, 39,
			96, 17,
			89, 5,
			81, 17,
			74, 32,
			41, -2,
			41, 35
		};
		
		int counter = 0;
		b2Vec2 rick_head1[33];
				
		for (int i = 0; i < 33; i++) {

			rick_head1[i].Set(PIXEL_TO_METERS(rick_head[counter]), PIXEL_TO_METERS(rick_head[counter + 1]));
			counter += 2;
			LOG("POINTS %i", rick_head1[i]);
		}

		body3.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));
		
		b2Body* b4 = world->CreateBody(&body3);

		b2ChainShape chain;
		chain.CreateLoop(rick_head1, 33);
		b2FixtureDef fixture2;
		fixture2.shape = &chain;
		b4->CreateFixture(&fixture2);



	}

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

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
				// Draw circles ------------------------------------------------
				case b2Shape::e_circle:
				{
					b2CircleShape* shape = (b2CircleShape*)f->GetShape();
					b2Vec2 pos = f->GetBody()->GetPosition();
					App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 255, 255, 255);
				}
				break;

				// Draw polygons ------------------------------------------------
				case b2Shape::e_polygon:
				{
					b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();
					int32 count = polygonShape->GetVertexCount();
					b2Vec2 prev, v;

					for(int32 i = 0; i < count; ++i)
					{
						v = b->GetWorldPoint(polygonShape->GetVertex(i));
						if(i > 0)
							App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);

						prev = v;
					}

					v = b->GetWorldPoint(polygonShape->GetVertex(0));
					App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);
				}
				break;

				// Draw chains contour -------------------------------------------
				case b2Shape::e_chain:
				{
					b2ChainShape* shape = (b2ChainShape*)f->GetShape();
					b2Vec2 prev, v;

					for(int32 i = 0; i < shape->m_count; ++i)
					{
						v = b->GetWorldPoint(shape->m_vertices[i]);
						if(i > 0)
							App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
						prev = v;
					}

					v = b->GetWorldPoint(shape->m_vertices[0]);
					App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
				}
				break;

				// Draw a single segment(edge) ----------------------------------
				case b2Shape::e_edge:
				{
					b2EdgeShape* shape = (b2EdgeShape*)f->GetShape();
					b2Vec2 v1, v2;

					v1 = b->GetWorldPoint(shape->m_vertex0);
					v1 = b->GetWorldPoint(shape->m_vertex1);
					App->renderer->DrawLine(METERS_TO_PIXELS(v1.x), METERS_TO_PIXELS(v1.y), METERS_TO_PIXELS(v2.x), METERS_TO_PIXELS(v2.y), 100, 100, 255);
				}
				break;
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
