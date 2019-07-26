#ifndef DEF_SERVERSETTINGS
#define DEF_SERVERSETTINGS
#include <string>

class ServerSettings{
/*Methods*/
    public:
    //Constructor :
    ServerSettings();
    
    //Getters :
    bool isVersusMode();
    int getVotingStandard();
    int getNbrPlayerMax();
    int getNbrPlayerCurrent();
    bool isFreeRoleChoice();
    std::string getServerName();
    std::string getServerPassword();
    std::string getServerLanguage();

    //Setters :
    void setVersusMode(bool versusMode_a);
    void setVotingStandard(int votingStandard_a);
    void setNbrPlayerMax(int nbrPlayersMax_a);
    void setNbrPlayerCurrent(int nbrPlayerCurrent_a);
    void setFreeRoleChoice(bool freeRoleChoice_a);
    void setServerName(std::string serverName_a);
    void setServerPassword(std::string serverPassword_a);
    void setServerLanguage(std::string serverLanguage_a);

/*Attributes*/
    private:
    bool versusMode;
    int votingStandard;
    int nbrPlayersMax;
    int nbrPlayerCurrent;
    bool freeRoleChoice;
    std::string serverName;
    std::string serverPassword;
    std::string serverLanguage;
};

#endif