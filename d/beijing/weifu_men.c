inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","韦府大门");
        set("long", @LONG
这里便是当朝第一宠臣，被康熙帝御封为『一等鹿鼎公』的韦公爷的居宅。
来到这里，一座富丽堂皇的高大建筑出现在你的眼前，大门两侧是两头高大的石
狮子。门上横着一块大匾，上面是大学士索额图亲笔提写的『鹿鼎公府』四个金
笔大字。门前站着个韦府的侍卫。
LONG );
	set("exits", ([
		"west" : "/d/beijing/weifu_zoulang1",
		"east" : "/d/beijing/wang_1",
	]));
	set("objects", ([
		"/d/beijing/npc/lilishi" : 1,
	]));
	set("coor/x", -20);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("li lishi", environment(me))) && dir == "west")
		return notify_fail("李力世喝道：别乱逛，公爷今天不见客。\n\n");
	return ::valid_leave(me, dir);
}
