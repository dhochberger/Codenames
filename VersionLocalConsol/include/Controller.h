#ifndef DEF_CONTROLLER
#define DEF_CONTROLLER

#include "Map.h"
#include "Settings.h"
#include "ServerSettings.h"

class Controller{
/*Methods*/
    public:
    //Map Interface
    bool isTeamOnePlaying();
    int blockColor(int idBlock);
    /*blockColor return 0/1/2/3 for Neutral/TeamOne Witness/TeamTwo Witness/Assassin*/
    std::string blockWord(int idBlock);
    bool isBlockSelected(int idBlock);
    int playBlock(int idBlock);
    /*playBlock return 0/1/2 for No one win/TeamOne Win/TeamTwo Win*/
    void newMap();

    //Settings Interface
    std::string getLanguage();
    int getMasterVolume();
    int getOldMasterVolume();
    int getMusicVolume();
    int getOldMusicVolume();
    int getEffectVolume();
    int getOldEffectVolume();
    std::string getColorTeamOne();
    std::string getColorTeamTwo();
    void setLanguage(std::string language_a);
    void setMasterVolume(int masterVolume_a);
    void setMusicVolume(int musicVolume_a);
    void setEffectVolume(int effectVolume_a);
    void setColorTeamOne(std::string colorTeamOne_a);
    void setColorTeamTwo(std::string colorTeamTwo_a);
    void mute();
    void unmute();
    bool isVolumeMuted();
    void defaultSettings();

    //ServerSettings Interface
    bool isVersusMode();
    int getVotingStandard();
    int getNbrPlayerMax();
    int getNbrPlayerCurrent();
    bool isFreeRoleChoice();
    std::string getServerName();
    std::string getServerPassword();
    std::string getServerLanguage();
    void setVersusMode(bool versusMode_a);
    void setVotingStandard(int votingStandard_a);
    void setNbrPlayerMax(int nbrPlayersMax_a);
    void setNbrPlayerCurrent(int nbrPlayerCurrent_a);
    void setFreeRoleChoice(bool freeRoleChoice_a);
    void setServerName(std::string serverName_a);
    void setServerPassword(std::string serverPassword_a);
    void setServerLanguage(std::string serverLanguage_a);
    void defaultServerSettings();

    //Online Interface
    void sendMap();
    int playBlockOnline(int idBlock);
    /*playBlockOnline have same return as playBlock*/
    void sendServerSettingsToCreate();
    void sendServerSettingsToJoin(ServerSettings chosenServer);
    void sendRematchInvitation();
    void sendChat(std::string message);
    void sendPlayerRole();
    void sendNewClue();
    void sendGameStarted();
    int receiveSomething();
    /*receiveSomething return 0 for a map
        1 for a block to play
        2 for a list of server
        3 for a rematch invitation
        4 for a chat message
        5 for your role
        6 for a clue*/

/*Attributes*/
    private:
    Map map;
    Settings set;
    ServerSettings ownServSet;
    ServerSettings tabOtherServSet[];
};

#endif