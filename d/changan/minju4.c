//Room: minju4.c

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set("long", @LONG
这里是一家民居住房，窗台上放着大大小的小陶盆瓷罐，里面种着花草之类
的东西，两扇窗子大开，飘出一股花草的清香味。民居里十分热闹，一张大木桌
子，周围放着几把椅子，几个邻里凑在一起，不知在谈什么。
LONG );
        set("exits", 
        ([ //sizeof() == 1
        	"north" : "/d/changan/huarui4",
        ]));

        set("coor/x", -390);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
