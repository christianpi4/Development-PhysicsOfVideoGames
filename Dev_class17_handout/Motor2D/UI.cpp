#include "UI.h"
#include "j1Gui.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"



UI::UI(int x, int y, UI* parent, j1Module* CallBack) : position(x, y)
{
	//atlas = App->gui->GetAtlas();
	this->parent = parent;

	callback = CallBack;
}

bool UI::Update(float dt) {

	return true;
}

bool UI::Draw() {
	if (atlas != nullptr)
	{
		App->render->Blit(atlas, position.x, position.y, &rect);
	}
	return true;
}

bool UI::CleanUp() {
	return true;
}

bool UI::Intersection()
{
	bool ret = false;

	iPoint mouse;

	App->input->GetMousePosition(mouse.x, mouse.y);

	if (mouse.x > position.x && mouse.x < position.x + rect.w &&
		mouse.y > position.y && mouse.y < position.y + rect.h)
	{
		ret = true;
	}

	return ret;
}