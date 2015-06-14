--
-- Author: Owl
-- Date: 2015-06-14 08:46:36
--
HttpRequest = import("app.Net.HttpRequest").new()

--init url
import("app.Net.ServerUrl")

--net handler load
import("app.Net.PacketHandler.LoginHandler")


--net packet send load
import("app.Net.Packet.LoginPacket")
