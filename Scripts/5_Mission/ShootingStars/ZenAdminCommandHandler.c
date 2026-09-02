#ifdef ZenModCore
modded class ZenAdminCommandHandler
{
	override bool HandleAdminCommand(PlayerBase player, string uid, string cmd, array<string> params)
	{
        if (super.HandleAdminCommand(player, uid, cmd, params))
            return true;

        MissionServer missionServer = MissionServer.Cast(g_Game.GetMission());
        if (!missionServer)
            return true;

        if (cmd == "star")
		{
			missionServer.SSM_ForceShootingStar();
			return true;
		}

        if (cmd == "starshower")
        {
            int starCount = 8;

            if (params && params.Count() > 0)
                starCount = params[0].ToInt();

            missionServer.SSM_ForceStarShower(starCount);
            return true;
        }

		return false;
	}
}
#endif