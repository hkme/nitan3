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
		return notify_fail("你只能撕布料的衣服。\n");

	if ((int)query("teared_count") >= 4)
		return notify_fail( name() + "的袖口，下□已经没有多馀的布可撕了。\n");

	message_vision("$N从" + name() + "撕下一条布条。\n", this_player() );
	add("teared_count", 1);
	ob = new("/clone/misc/bandage");
	ob->set_name("从" + name() + "撕下的布条", ({ "cloth piece", "piece", "cloth" }) );
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
        set_temp("no_wear", "现在" + name() + "还是湿乎乎的，你没法穿。\n");
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
        message("vision", name() + "已经干了。\n", environment());
}

string extra_long()
{
        string str;
        
        str =  "物品类型    ：    防具\n";
        str += "属    性    ：    衣服\n";
        str += sprintf("防    护    ：    %d\n", query("armor_prop/armor"));
        str += sprintf("重    量    ：    %d\n", this_object()->query_weight());
        str += sprintf("使用方式    ：    输入指令 wear %s 装备。\n", query("id"));
        str += sprintf("                  输入指令 remove %s 卸下。\n", query("id"));
        if (this_object()->query_autoload())
                str += "下线丢失    ：    否\n";
        else
                str += "下线丢失    ：    是\n";
        return str;
}
