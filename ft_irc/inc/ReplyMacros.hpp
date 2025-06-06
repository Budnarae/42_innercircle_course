#pragma once

//Replys
#define RPL_WELCOME(NICK, USER, HOST) 		        (std::string("001 ") + NICK + " Welcome to the Internet Relay Network " + NICK + "!" + USER + "@" + HOST + "\r\n")
#define RPL_CHANNELMODEIS(CHANNEL, MODE)	        (std::string("324 ") + CHANNEL + " " + MODE + "\r\n")
#define RPL_NOTOPIC(CHANNEL)				        (std::string("331 ") + CHANNEL + " :No topic is set\r\n")
#define RPL_TOPIC(CHANNEL, TOPIC)			        (std::string("332 ") + CHANNEL + " :" + TOPIC + "\r\n")
#define RPL_INVITING(CHANNEL, NICK)			        (std::string("341 ") + (CHANNEL) + " " + (NICK) + "\r\n")
// 원래 표준에서는 RPL_NAMREPLY, RPL_ENDOFNAMES에 NICK이 포함이 되지 않지만
// 역시 상용 클라이언트가 표준을 안지켜서 호환이 안되기 때문에 아래와 같이 임의로 수정합니다.
#define RPL_NAMREPLY(NICK, CHANNEL, LIST_OF_NICKS)  (std::string("353 ") + (NICK) + " = " + (CHANNEL) + " :" + (LIST_OF_NICKS) + "\r\n")
#define RPL_ENDOFNAMES(NICK, CHANNEL)				(std::string("366 ") + (NICK) + " " + (CHANNEL) + " :End of /NAMES list\r\n")

//Errors
#define ERR_NOSUCHNICK(NICK)				        (std::string("401 ") + NICK + " :No such nick\r\n")
#define ERR_NOSUCHCHANNEL(CHANNEL)			        (std::string("403 ") + (CHANNEL) + " :No such channel\r\n")
#define ERR_CANNOTSENDTOCHAN(CHAN)			        (std::string("404 ") + CHAN + " :Cannot send to channel\r\n")
#define ERR_TOOMANYCHANNELS(CHANNEL)		        (std::string("405 ") + (CHANNEL) + " :You have joined too many channels\r\n")
#define ERR_NORECIPIENT(COMMAND)			        (std::string("411 ") + ":No recipient given " + COMMAND + "\r\n")
#define ERR_NOTEXTTOSEN						        (std::string("412 :No text to send\r\n"))
#define ERR_NONICKNAMEGIVEN 				        (std::string("431") + " :No nickname given\r\n")
#define ERR_ERRONEUSNICKNAME(NICK)			        (std::string("432 ") + NICK + " :Erroneous nickname\r\n")
#define ERR_NICKNAMEINUSE(NICK)				        (std::string("433 ") + NICK + " :Nickname is already in use\r\n")
#define ERR_NICKCOLLISION(NICK, USER, HOST)         (std::string("436 ") + NICK + " :Nickname collision KILL from " + USER + "@" + HOST + "\r\n")
#define ERR_UNAVAILRESOURCE(NAME, TYPE) 	        (std::string("437 ") + NAME + " :" + TYPE + " is temporarily unavailable\r\n") //can be used for both nick and channel
#define ERR_USERNOTINCHANNEL(NICK, CHANNEL)	        (std::string("441 ") + NICK + " " + CHANNEL + " :They aren't on that channel\r\n")
#define ERR_NOTONCHANNEL(CHANNEL)			        (std::string("442 ") + (CHANNEL) + " :You're not on that channel\r\n")
#define ERR_USERONCHANNEL(USER, CHANNEL)	        (std::string("443 ") + (USER) + " " + (CHANNEL) + " :is already on channel\r\n")
#define ERR_NEEDMOREPARAMS(COMMAND) 		        (std::string("461 ") + COMMAND + " :Not enough parameters\r\n")
#define ERR_ALREADYREGISTRED				        (std::string("462 :Unauthorized command (already registered)\r\n"))
#define ERR_KEYSET(CHANNEL)					        (std::string("467 ") + CAHNNEL + " :Channel key already set\r\n")
#define ERR_CHANNELISFULL(NICK, CHANNEL)			(std::string("471 ") + NICK + " " + (CHANNEL) + " :Cannot join channel (channel is full)\r\n")
#define ERR_UNKNOWNMODE(CHAR, CHANNEL)		        (std::string("472 ") + CHAR + " :is unknown mode char to me for " + CHANNEL + "\r\n")
#define ERR_INVITEONLYCHAN(CHANNEL) 		        (std::string("473 ") + (CHANNEL) + " :Cannot join channel (+i)\r\n")
// 원래 표준에서는 Cannot join channel (+k)와 같이 응답해야 하지만
// 역시 상용 클라이언트가 표준을 안지켜서 호환이 안되기 때문에 아래와 같이 임의로 수정합니다.
#define ERR_BADCHANNELKEY(NICK, CHANNEL) 			        (std::string("475 ") + NICK + " " + CHANNEL + " :Cannot join channel (incorrect channel key)\r\n")
#define ERR_CHANOPRIVSNEEDED(CHANNEL)		        (std::string("482 ") + (CHANNEL) + " :You're not channel operator\r\n")
#define ERR_RESTRICTED						        (std::string("484 :Your connection is restricted!\r\n"))
