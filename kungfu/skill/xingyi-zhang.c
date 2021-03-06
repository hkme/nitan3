// xingyi-zhang 斗转星移掌
// by Lonely

inherit SKILL;

string *action_msg = ({
        "$N使一招「幻形变影」，双手划了个半圈，按向$n的$l",
        "$N左手虚按，右手使一招「星星点点」，向$n的$l推去",
        "$N双手握拳，向前向后划弧，一招「漫天星斗」打向$n的$l",
        "$N左手虚划，右手一记「五斗星辰」击向$n的腰部",
        "$N施出「北斗七星」，右手击向$n的$l，左手攻向$n的裆部",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_combine(string combo)  
{
        object me = this_player();
        mapping myfam;

        if (mapp(myfam = me->query("family")) && myfam["master_name"] == "慕容博") 
                 return combo == "canhe-zhi";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练斗转星移掌必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学斗转星移掌。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练斗转星移掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))], 
                "force" : 260 + random(60),
                "attack": 50 + random(10), 
                "dodge" : 50 + random(10), 
                "parry" : 50 + random(10), 
                "damage_type" : random(2)?"瘀伤":"内伤", 
        ]); 
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练斗转星移掌。\n");
        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xingyi-zhang/" + action;
}

