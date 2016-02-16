#include "AllegroCore.h"

AllegroCore::AllegroCore()
{
	display = nullptr;
	timer = nullptr;
	eventQueue = nullptr;
	backgroundImage = nullptr;
	roadImage = nullptr;
	mainFont = nullptr;
	fpsTimeout = 60;
	views = new BaseView*[3];
}

void AllegroCore::Initialize(int width, int height, int r, int g, int b)
{
	if (!al_init())	throw "Allegro initialize error!";	// инициализация библиотеки Allegro

	// initialize addon
	al_init_image_addon();
	al_init_font_addon();	// initialize the font addon
	al_init_ttf_addon();	// initialize the ttf (True Type Font) addon
	
	al_install_mouse();		// инициализация мыши

	this->width = width;
	this->height = height;

	display = al_create_display(width, height);	// создаем экран заданного размера
	if (display == nullptr) throw "Display creation error!";
	
	if (!al_install_keyboard()) throw "Install keyboard error!";

	timer = al_create_timer(1.0 / fpsTimeout);
	if (timer == nullptr) throw "Timer creation error!";

	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr) throw "Event queue creation error!";
	
	mainFont = al_load_ttf_font("Resources/Fonts/BRUX.ttf", 60, 0);
	if (mainFont == nullptr) throw "Font creation error!";

	backgroundImage = al_load_bitmap("Resources/Images/Menu.png");	// картинка фона
	if (backgroundImage == nullptr) throw "Load image error!";

	roadImage = al_load_bitmap("Resources/Images/level -1.png");
	if (roadImage == nullptr) throw "Load image error!";

	al_set_target_bitmap(al_get_backbuffer(display));	// отрисовка в буфер

	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
	backgroundColor.a = 0;

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	
	currentView = new MainMenuView(width, height, backgroundImage, mainFont);
	views[(int)ViewType::MainMenu] = new MainMenuView(width, height, backgroundImage, mainFont);
	views[(int)ViewType::GameView] = new GameView(width, height, roadImage, mainFont);
	views[(int)ViewType::AboutMenu] = new AboutView(width, height, backgroundImage, mainFont);


	al_clear_to_color(al_map_rgb(r, g, b));	// замена цвета фона

	al_flip_display();	// подмена экрана буфером

	firstLevel = new Level(width, height, 0);
}



void AllegroCore::Main()
{
	KeyboardController keyControl;

	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	ALLEGRO_MOUSE_STATE state;

	int x = 0, y = 0;
	
	//al_convert_mask_to_alpha(mainAtlas, al_map_rgb(0, 0, 0));

	while (true)
	{
		al_wait_for_event(eventQueue, &ev);

		al_register_event_source(eventQueue, al_get_mouse_event_source());

		al_get_mouse_state(&state);	// считать позицию курсора

		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue))
		{
			currentView->Update();
			al_flip_display();
		}

		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && state.buttons & 1)	// нажата ли левая кнопка мыши?
		{
			printf("Mouse position: (%d, %d)\n", state.x, state.y);
			ViewType view = currentView->CheckSwitchView(state.x, state.y);
			if (view == ViewType::Exit) break;
			
			// произошло переключение на другое меню
			if (currentView->GetViewType() != (ViewType)view)
			{
				currentView = views[(int)view];

				// произошло переключение на геймлей (игровой уровень)
				if (view == ViewType::GameView)
				{
					((GameView*)currentView)->StartLevel(firstLevel);
				}
			}	
		}
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				currentView = views[(int)ViewType::MainMenu];
			}

			if (currentView->GetViewType() == ViewType::GameView)
			{
				((GameView*)currentView)->SetDirection(keyControl.GetDirection(ev));
			}
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (currentView->GetViewType() == ViewType::GameView)
			{
				((GameView*)currentView)->SetDirection(keyControl.GetDirection(ev));
			}
		}

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;	// для работы кнопки close
	}
}

AllegroCore::~AllegroCore()
{
	
}