// cloth.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
	        set("armor_type", TYPE_CLOTH);

        ::setup();
}

void init()
{
	add_action("do_tear", "tear");
}

int do_tear(string str)
{
	object ob;

	if (! id(str)) return 0;

	if ((string)query("material") != "cloth")
		return notify_fail("��ֻ��˺���ϵ��·���\n");

	if ((int)query("teared_count") >= 4)
		return notify_fail( name() + "����ڣ��¡��Ѿ�û�ж��ŵĲ���˺�ˡ�\n");

	message_vision("$N��" + name() + "˺��һ��������\n", this_player() );
	add("teared_count", 1);
	ob = new("/clone/misc/bandage");
	ob->set_name("��" + name() + "˺�µĲ���", ({ "cloth piece", "piece", "cloth" }) );
	if (! ob->move(this_player()))
		ob->move(environment(this_player()));
	return 1;
}

int washed(int n)
{
        switch (query("material"))
        {
        case "cloth":
                n += n * 3 / 10;
                break;
        case "leather":
                break;
        case "silk":
                n -= n * 3 / 10;
                break;
        case "bamboo":
                n -= n * 5 / 10;
                break;
        case "steel":
                n -= n * 7 / 10;
                break;
        }
        set_temp("no_wear", "����" + name() + "����ʪ�����ģ���û������\n");
        delete_temp("daub");
        remove_call_out("dry_cloth");
        if (n) call_out("dry_cloth", n);
        return n;
}

void dry_cloth()
{
        if (! objectp(this_object()))
                return;
        delete_temp("no_wear");
        message("vision", name() + "�Ѿ����ˡ�\n", environment());
}

string extra_long()
{
        string str;
        
        str =  "��Ʒ����    ��    ����\n";
        str += "��    ��    ��    �·�\n";
        str += sprintf("��    ��    ��    %d\n", query("armor_prop/armor"));
        str += sprintf("��    ��    ��    %d\n", this_object()->query_weight());
        str += sprintf("ʹ�÷�ʽ    ��    ����ָ�� wear %s װ����\n", query("id"));
        str += sprintf("                  ����ָ�� remove %s ж�¡�\n", query("id"));
        if (this_object()->query_autoload())
                str += "���߶�ʧ    ��    ��\n";
        else
                str += "���߶�ʧ    ��    ��\n";
        return str;
}