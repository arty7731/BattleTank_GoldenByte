#include "AllegroCore.h"

AllegroCore::AllegroCore()
{
	display = nullptr;
	timer = nullptr;
	eventQueue = nullptr;
	backgroundImage = nullptr;
	mainAtlas = nullptr;
	fpsTimeout = 60;
}

void AllegroCore::Initialize(int width, int height, int r, int g, int b)
{
	if (!al_init())	throw "Allegro initialize error!";	// инициализация библиотеки Allegro
	
	al_init_image_addon();
	
	this->width = width;
	this->height = height;

	display = al_create_display(width, height);	// создаем экран заданного размера
	if (display == nullptr) throw "Display creation error!";
	
	if (!al_install_keyboard()) throw "Install keyboard error!";

	timer = al_create_timer(1.0 / fpsTimeout);
	if (timer == nullptr) throw "Timer creation error!";

	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr) throw "Event queue creation error!";
	
	backgroundImage = al_load_bitmap("./Resources/Images/Menu.jpg");	// картинки пока нет!!!
	//mainAtlas = al_load_bitmap("./Resources/Images/Menu.jpg");
	//if (backgroundImage == nullptr || mainAtlas == nullptr) throw "Load image error!";
	if (backgroundImage == nullptr) throw "Load image error!";

	al_set_target_bitmap(al_get_backbuffer(display));	// отрисовка в буфер

	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
	backgroundColor.a = 0;

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	
	al_clear_to_color(al_map_rgb(r, g, b));	// замена цвета фона
	al_flip_display();	// подмена экрана буфером
	//al_rest(5);	// задержка выхода из окна (sleep 5000)
}

void AllegroCore::Main()
{
	al_start_timer(timer);
	ALLEGRO_EVENT ev;
	
	int x = 0, y = 0;
	
	//al_convert_mask_to_alpha(mainAtlas, al_map_rgb(0, 0, 0));

	while (true)
	{
		al_wait_for_event(eventQueue, &ev);

		
		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue))
		{
			al_draw_bitmap(backgroundImage, 0, 0, 0);
			
			al_flip_display();
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;	// для работы кнопки close
	}
}


AllegroCore::~AllegroCore()
{
	
}