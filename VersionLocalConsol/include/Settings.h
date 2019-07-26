#ifndef DEF_SETTINGS
#define DEF_SETTINGS

#include <string>

class Settings{
/*Methods*/
    public:
    //Constructor :
    Settings();

    //Getters :
    std::string getLanguage();
    int getMasterVolume();
    int getOldMasterVolume();
    int getMusicVolume();
    int getOldMusicVolume();
    int getEffectVolume();
    int getOldEffectVolume();
    std::string getColorTeamOne();
    std::string getColorTeamTwo();
    bool isVolumeMuted();

    //Setters :
    void setLanguage(std::string language_a);
    void setMasterVolume(int masterVolume_a);
    void setMusicVolume(int musicVolume_a);
    void setEffectVolume(int effectVolume_a);
    void setColorTeamOne(std::string colorTeamOne_a);
    void setColorTeamTwo(std::string colorTeamTwo_a);
    void mute();
    void unmute();

/*Attributes*/
    private:
    std::string language;
    int masterVolume;
    int oldMasterVolume;
    int musicVolume;
    int oldMusicVolume;
    int effectVolume;
    int oldEffectVolume;
    std::string colorTeamOne;
    std::string colorTeamTwo;
    bool muted;
};

#endif