inherit ROOM;

void create()
{
        set("short", "��԰С·");
        set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ
�ͷף�һ���������֣�ʢ���ŷۺ���һ�������һƬ��������
�ߡ������Կ����۷䡸���ˡ����ڻ�����Ϸ���æ����ͣ����
����Գ���ߴզ����
LONG );
        set("outdoors", "wudang");
        set("exits", ([
                "west" : __DIR__"tyroad10",
                "east" : __DIR__"tyroad12",
        ]));
	set("coor/x", -280);
	set("coor/y", -310);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}