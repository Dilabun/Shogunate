#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QListWidget>


//i know im a noob
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //idk what this shit is tbh! lol! XD
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int const roninCost = 2;
    int const kenshiCost = 2;
    int const kyudoCost = 2;
    int const samuraiCost = 3;
    int const upgradeCost = 1;
    int const shogunCost = 5;
    int const hatamotoCost = 4;
    int playerEnergy;
    int totalDamage1;
    int totalDamage2;
    int totalDamage3;
    int playerHealth = 100;
    int opponentHealth = 100;
    int randomIndexBoi1;
    int randomIndexOpp1;
    int randomIndexBoi2;
    int randomIndexOpp2;
    int randomIndexBoi3;
    int randomIndexOpp3;
    int tempEnergy = 0;
    int healturns = 3;

    int damageGenerated1;
    int damageGenerated2;
    int damageGenerated3;
    int damageGenerated4;
    int damageGenerated5;
    int damageGenerated6;

    int level = 1;
    bool attacker1 = false;
    bool attacker2 = false;
    bool attacker3 = false;
    bool attacker4 = false;
    bool attacker5 = false;
    bool attacker6 = false;
    bool container1 = false;
    bool container2 = false;
    bool container3 = false;
    bool container4 = false;
    bool container5 = false;
    bool team1 = false;
    bool team2 = false;
    bool team3 = false;
    bool iswager = false;

    bool tutorialtask1 = false;
    bool tutorialtask2 = false;
    bool tutorialtask1bundle = false;

    bool revertgoshi1 = false;
    bool revertgoshi2 = false;
    bool revertgoshi3 = false;

    std::string container1Card;
    std::string container2Card;
    std::string container3Card;
    std::string container4Card;
    std::string container5Card;
    std::string attacker1Fighter;
    std::string attacker2Fighter;
    std::string attacker3Fighter;
    std::string attacker4Fighter;
    std::string attacker5Fighter;
    std::string attacker6Fighter;
    std::string selectedCard;


    QPixmap cleanse;
    QPixmap kenshilevel1;
    QPixmap kenshilevel2;
    QPixmap kenshilevel3;
    QPixmap kyudolevel1;
    QPixmap kyudolevel2;
    QPixmap kyudolevel3;
    QPixmap roninlevel1;
    QPixmap roninlevel2;
    QPixmap roninlevel3;
    QPixmap samurai;
    QPixmap strike;
    QPixmap upgrade;
    QPixmap wager;
    QPixmap diminish;
    QPixmap expell;
    QPixmap artOfWar;
    QPixmap arrow;
    QPixmap levels;
    QPixmap shogun;
    QPixmap hatamoto;
    QPixmap goshi;
    QPixmap fortify;
    QPixmap blessing;
    QPixmap restore;
    QPixmap sumo;
    QPixmap smith;

    QPixmap enemypicture10;
    QPixmap enemypicture9;
    QPixmap enemypicture8;
    QPixmap enemypicture7;
    QPixmap enemypicture6;
    QPixmap enemypicture5;
    QPixmap enemypicture4;
    QPixmap enemypicture3;
    QPixmap enemypicture2;
    QPixmap enemypicture1;



    QString cardsArray[5];


    int cardsChosen = 0;
    int oppinfo = 1;





    //check if the card has already been clicked
    bool alreadyClicked1 = false;
    bool alreadyClicked2 = false;
    bool alreadyClicked3 = false;
    bool alreadyClicked4 = false;
    bool alreadyClicked5 = false;

    //player card stack (initalized with seven)
    std::vector<std::string> playerCards;
    std::vector<std::string> cardStack;
    std::vector<std::string> playerCardsStart;
    std::vector<std::string> cardStorage;


public slots:
    void startMainButtonClicked();
    void tutorialProcess();
    void tutorialOpponent();
    void giveCards();
    void giveCardSelection();
    void tutorialGiveCards();

    void endTurnBetter1();
    void endTurnBetter2();
    void endTurnBetter3();
    void endTurnTutorial();
    void tutorialYes();
    void tutorialNo();
    void team1select();
    void team2select();
    void team3select();
    void opponent1Begin();
    void opponent1();
    void opponent2();
    void opponent3();
    void opponent4();
    void opponent5();
    void opponent6();
    void opponent7();
    void opponent8();
    void opponent9();
    void opponent10();
    void checkHealth();
    void giveHealth();





protected:
    void mousePressEvent(QMouseEvent *event) override;



private slots:
    void on_mydeck_clicked();

    void on_roninbutton_clicked();

    void on_kenshibutton_clicked();

    void on_kyudobutton_clicked();

    void on_samuraibutton_clicked();

    void on_diminishbutton_clicked();

    void on_upgradebutton_clicked();

    void on_wagerbutton_clicked();

    void on_expellbutton_clicked();

    void on_blessingbutton_clicked();

    void on_fortifybutton_clicked();

    void on_strikebutton_clicked();

    void on_goshibutton_clicked();

    void on_hatamotobutton_clicked();

    void on_shogunbutton_clicked();


    void on_removecard_clicked();

    void on_addbutton_clicked();


    void on_return1_clicked();

    void on_pushButton_clicked1();
    void on_pushButton_clicked2();
    void on_pushButton_clicked3();
    void on_pushButton_clicked4();
    void on_pushButton_clicked5();
    void on_pushButton_clicked6();

    void on_next_clicked();

    void on_endturn_clicked();

    void on_begin_clicked();

    void on_yescardbutton_clicked();

    void on_nocardbutton_clicked();

    void on_oppnext_clicked();

    void on_oppback_clicked();

    void on_gobackinfo_clicked();

    void on_info_clicked();

private:
    Ui::MainWindow *ui;
    QPoint originalPos1;
    QPoint originalPos2;
    QPoint originalPos3;
    QPoint originalPos4;
    QPoint originalPos5;
};
#endif // MAINWINDOW_H
