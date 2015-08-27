--
-- Author: Owl
-- Date: 2015-06-14 08:46:36
--
PacketHandler = {}

import("app.Net.NetUtil")

HttpRequest = import("app.Net.HttpRequest").new()

import("app.Net.NetCode")
--init url
import("app.Net.ServerUrl")

--net handler load
import("app.Net.PacketHandler.LoginHandler")


--net packet send load
import("app.Net.Packet.LoginPacket")
