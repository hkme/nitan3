inherit ROOM;

void create()
{
      set("short", "华藏庵西廊");
      set("long", @LONG
这里是峨嵋华藏庵西廊。走廊往南通往禅房，东通往广场。
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "south" : __DIR__"hcawest2",
          "east"  : __DIR__"hcaguangchang", 
      ]));
      set("coor/x", -570);
	set("coor/y", -330);
	set("coor/z", 220);
	setup();
      replace_program(ROOM);
}
