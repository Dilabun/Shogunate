#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QTimer>
#include <cstdlib>
#include <stdlib.h>
#include <QListWidget>
#include <QApplication>
#include <QLabel>
#include <QMovie>
#include <QMessageBox>
#include <QCoreApplication>
#include <random>
#include <QtGlobal>

using namespace std;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d; letter-spacing: 2px;\">ブロウ リアリー ユーズド グーグル トランスレート</span></p></body></html>");


    playerCards.push_back("kenshi");
    playerCards.push_back("kyudo");
    playerCards.push_back("ronin");
    playerCards.push_back("samurai");
    playerCards.push_back("upgrade");
    playerCards.push_back("diminish");







    cleanse = QPixmap(":/images/cleanse.png");
    kenshilevel1 = QPixmap(":/images/kenshi level 1.png");
    kenshilevel2 = QPixmap(":/images/kenshi level 2.png");
    kenshilevel3 = QPixmap(":/images/kenshi level 3.png");
    kyudolevel1 = QPixmap(":/images/kyudo level 1.png");
    kyudolevel2 = QPixmap(":/images/kyudo level 2.png");
    kyudolevel3 = QPixmap(":/images/kyudo level 3.png");
    roninlevel1 = QPixmap(":/images/ronin level 1.png");
    roninlevel2 = QPixmap(":/images/ronin level 2.png");
    roninlevel3 = QPixmap(":/images/ronin level 3.png");
    levels = QPixmap(":/images/levels.png");
    samurai = QPixmap(":/images/samurai.png");
    strike = QPixmap(":/images/strike.png");
    upgrade = QPixmap(":/images/upgrade.png");
    wager = QPixmap(":/images/wager.png");
    diminish = QPixmap(":/images/diminish.png");
    expell = QPixmap(":/images/expell.png");
    shogun = QPixmap(":/images/shogun.png");
    hatamoto = QPixmap(":/images/hatamoto.png");
    goshi = QPixmap(":/images/goshi.png");
    fortify = QPixmap(":/images/fortify.png");
    artOfWar = QPixmap(":/images/artofwar.png");
    blessing = QPixmap(":/images/blessing.png");
    arrow = QPixmap(":/images/arrowREAL.png");

    restore = QPixmap(":/images/restore.png");
    sumo = QPixmap(":/images/sumo.png");
    smith = QPixmap(":/images/smith.png");

    enemypicture10 = QPixmap(":/images/enemypicture (10).png");
    enemypicture9 = QPixmap(":/images/enemypicture (9).png");
    enemypicture8 = QPixmap(":/images/enemypicture (8).png");
    enemypicture7 = QPixmap(":/images/enemypicture (7).png");
    enemypicture6 = QPixmap(":/images/enemypicture (6).png");
    enemypicture5 = QPixmap(":/images/enemypicture (5).png");
    enemypicture4 = QPixmap(":/images/enemypicture (4).png");
    enemypicture3 = QPixmap(":/images/enemypicture (3).png");
    enemypicture2 = QPixmap(":/images/enemypicture (2).png");
    enemypicture1 = QPixmap(":/images/enemypicture (1).png");

    originalPos1 = ui->container1card->pos();
    originalPos2 = ui->container2card->pos();
    originalPos3 = ui->container3card->pos();
    originalPos4 = ui->container4card->pos();
    originalPos5 = ui->container5card->pos();
    ui->stackedWidget->setCurrentIndex(0);
    ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");



   connect(ui->card1button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked1);
   connect(ui->card2button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked2);
   connect(ui->card3button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked3);
   connect(ui->card4button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked4);
   connect(ui->card5button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked5);
    connect(ui->card6button, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked6);
    connect(ui->endturnbuttontutorial, &QPushButton::clicked, this, &MainWindow::endTurnTutorial);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::startMainButtonClicked);
    connect(ui->yestutorial, &QPushButton::clicked, this, &MainWindow::tutorialYes);
    connect(ui->notutorial, &QPushButton::clicked, this, &MainWindow::tutorialNo);
    connect(ui->team1select, &QPushButton::clicked, this, &MainWindow::team1select);
    connect(ui->team2select, &QPushButton::clicked, this, &MainWindow::team2select);
    connect(ui->team3select, &QPushButton::clicked, this, &MainWindow::team3select);

    ui->maintitle_3->raise();
    ui->maintitle_3->raise();
    ui->yestutorial->raise();
    ui->yestutorial->raise();
    ui->notutorial->raise();
    ui->notutorial->raise();
    ui->tutorialtext->lower();
    ui->tutorialtext->lower();
    ui->hand1->lower();
    ui->hand1->lower();

    ui->hand2->lower();
    ui->hand2->lower();
    ui->hand3->lower();
    ui->hand3->lower();
    ui->hand4->lower();
    ui->hand4->lower();
    ui->hand5->lower();
    ui->hand5->lower();
    ui->hand6->lower();
    ui->hand6->lower();
    ui->hand7->lower();
    ui->hand7->lower();
    ui->hand8->lower();
    ui->hand8->lower();

    ui->attack1->lower();
    ui->attack1->lower();
    ui->attack2->lower();
    ui->attack2->lower();
    ui->attack3->lower();
    ui->attack3->lower();
    ui->attack4->lower();
    ui->attack4->lower();
    ui->attack5->lower();
    ui->attack5->lower();
    ui->attack6->lower();
    ui->attack6->lower();
    ui->move1->lower();
    ui->move1->lower();
    ui->move2->lower();
    ui->move2->lower();


    playerCardsStart = playerCards;

    opponentHealth = 100;


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::opponent1Begin()
{

}

void MainWindow::on_mydeck_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

    //playercards list
    for (int i = 0; i < playerCards.size(); i++) {
        std::string current = playerCards[i];
        ui->QlistWidgetDeck->setIconSize(QSize(64, 64)); // Adjust the width and height as needed

        QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/" + QString::fromStdString(current) + "f.png"), QString::fromStdString(current), ui->QlistWidgetDeck);
        ui->QlistWidgetDeck->addItem(item);

        // Set text color for each item
        item->setForeground(QColor(188, 0, 45));

    }

    //cardstorage list
    for (int i = 0; i < cardStorage.size(); i++) {
           std::string current = cardStorage[i];
           ui->QlistWidgetStorage->setIconSize(QSize(64, 64)); // Adjust the width and height as needed

           QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/" + QString::fromStdString(current) + "f.png"), QString::fromStdString(current), ui->QlistWidgetStorage);
           ui->QlistWidgetStorage->addItem(item);

           // Set text color for each item
           item->setForeground(QColor(188, 0, 45));

       }
    ui->decktitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Deck " + QString::number(playerCards.size()) + "/20</span></div>");


}


void addStringsToQListWidget(const vector<string>& playerCards, QListWidget* QlistWidgetDeck) {
    for(const auto& str : playerCards) {
        QString qstr = QString::fromStdString(str);
        QListWidgetItem* item = new QListWidgetItem(qstr);
        QlistWidgetDeck->addItem(item);
    }
}

void MainWindow::startMainButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::tutorialYes()
{
   //ui->stackedWidget->setCurrentIndex(3);
   //tutorialProcess();
    ui->maintitle_3->lower();
    ui->maintitle_3->lower();
    ui->yestutorial->lower();
    ui->yestutorial->lower();
    ui->notutorial->lower();
    ui->notutorial->lower();
    ui->tutorialtext->raise();
    ui->tutorialtext->raise();
    ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Welcome to the tutorial!<br>ウェルコム・ター・ザー・トユートーリアル</span></p></body></html>");
    QTimer::singleShot(2800, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">This is a turn-based card game, you will utilize a set of cards to conquer your opponent<br>ジス・イズ・ターン・ベースト・カード・ゲーム・ユー・ウィル・ユース・カードズ・ター・コンカー・オポーネント</span></p></body></html>");
        ui->circleoflife->setPixmap(QPixmap(":/images/cardgame.png"));
        ui->circleoflife->raise();
        ui->circleoflife->raise();
    });
    QTimer::singleShot(6000, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Lets go over the basics<br>レッツ・ゴー・オーバー・ザー・ベーシクス</span></p></body></html>");
        ui->circleoflife->setPixmap(QPixmap(":/images/cat.png"));
    });
    QTimer::singleShot(8000, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Every turn you will be given cards from your deck, you can have 5 cards in your hand<br>エブリー・ターン・ユー・ウィル・ビー・ギブン・カードズ・フロム・ヨー・デック・ユー・キャン・ハブ・ファイブ・カードズ・イン・ヨー・ハンド</span></p></body></html>");
        ui->circleoflife->lower();
        ui->circleoflife->lower();
        ui->hand1->raise();
        ui->hand1->raise();
        ui->hand2->raise();
        ui->hand2->raise();
        ui->hand3->raise();
        ui->hand3->raise();
        ui->hand4->raise();
        ui->hand4->raise();
        ui->hand5->raise();
        ui->hand5->raise();
        ui->hand6->raise();
        ui->hand6->raise();
        ui->hand7->raise();
        ui->hand7->raise();
        ui->hand8->raise();
        ui->hand8->raise();

    });
    QTimer::singleShot(11100, this, [this]() {
        ui->hand8->lower();
        ui->hand8->lower();
        ui->card1->raise();
        ui->card1->raise();

        ui->card1_2->raise();
        ui->card1_2->raise();

        ui->card1_3->raise();
        ui->card1_3->raise();

        ui->card1_4->raise();
        ui->card1_4->raise();

        ui->card1_5->raise();
        ui->card1_5->raise();
    });

    QTimer::singleShot(13000, this, [this]() {
         ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">You will utilize these cards, and play them in these 3 lanes<br>ユー・ウィル・ユーティライズ・ジーズ・カードズ・アンド・プレー・ゼム・イン・ジーズ・スリー・レーンズ</span></p></body></html>");
         ui->attack1->raise();
         ui->attack1->raise();
         ui->attack2->raise();
         ui->attack2->raise();
         ui->attack3->raise();
         ui->attack3->raise();
         ui->attack4->raise();
         ui->attack4->raise();
         ui->attack5->raise();
         ui->attack5->raise();
         ui->attack6->raise();
         ui->attack6->raise();
    });

    QTimer::singleShot(15000, this, [this]() {
        ui->move1->raise();
        ui->move1->raise();
        ui->move2->raise();
        ui->move2->raise();
        ui->card1_2->lower();
        ui->card1_2->lower();
        ui->card1_4->lower();
        ui->card1_4->lower();
        ui->attacker1t->raise();
        ui->attacker1t->raise();
        ui->attacker3t->raise();
        ui->attacker3t->raise();
    });

    QTimer::singleShot(16000, this, [this]() {
        ui->move1->lower();
        ui->move1->lower();
        ui->move2->lower();
        ui->move2->lower();
        ui->attacker4t->raise();
        ui->attacker4t->raise();
        ui->attacker6t->raise();
        ui->attacker6t->raise();

    });

    QTimer::singleShot(17000, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">At the end of the turn, these cards will fight!<br>	アット・ザー・エンド・オブ・ザー・ターン・ジーズ・カードズ・ウィル・ファイト</span></p></body></html>");
    });

    QTimer::singleShot(21000, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Damage is randomly rolled for each card, based on their attack range<br>ダミッジ・イズ・ロールド・フォー・イーチ・カード・ベースト・オン・ゼア・アタック・レーンジ</span></p></body></html>");
        ui->range1->raise();
        ui->range1->raise();
        ui->range2->raise();
        ui->range2->raise();
        ui->range3->raise();
        ui->range3->raise();
        ui->range4->raise();
        ui->range4->raise();
    });

    QTimer::singleShot(24500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">This attack range can be increased for some cards by upgrading<br>ジス・アタック・レーンジ・キャン・ビー・インクリースト・フォー・サム・カードズ・バイ・アプグレーディング</span></p></body></html>");
        ui->circlet->raise();
        ui->circlet->raise();


    });

    QTimer::singleShot(29500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Damage can also be doubled by capitalizing on a card's weakness!<br>ダミッジ・キャン・オールソー・ビー・ダブルド・バイ・キャピタライジング・オン・アー・カードズ・ウィークネス</span></p></body></html>");
        ui->circleoflife->setPixmap(QPixmap(":/images/artofwar.png"));
        ui->circleoflife->raise();
        ui->circleoflife->raise();
        ui->circlet->lower();
        ui->circlet->lower();


    });

    QTimer::singleShot(34000, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Learn more about card information and weakness in the deck builder<br>ラーン・モー・アー・カードズ・インフォメーション・アンド・ウィークネス・イン・ザー・デック・ビルダー</span></p></body></html>");
        ui->circleoflife->lower();
        ui->circleoflife->lower();
    });

    QTimer::singleShot(37500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">The card that rolls a higher number survives, and the other is discarded<br>ザー・カード・ザット・ロールズ・アー・ハイアー・ナンバー・サバイブズ・アンド・ザー・アザー・イズ・ディスカーディッド</span></p></body></html>");
        ui->damagedone1->raise();
        ui->damagedone1->raise();
        ui->damagedone2->raise();
        ui->damagedone2->raise();
        ui->damagedone3->raise();
        ui->damagedone3->raise();
        ui->damagedone4->raise();
        ui->damagedone4->raise();

    });

    QTimer::singleShot(39000, this, [this]() {

        ui->damagetotal1->raise();
        ui->damagetotal1->raise();
        ui->damagetotal2->raise();
        ui->damagetotal2->raise();

    });

    QTimer::singleShot(40500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">The leftover damage between the two attackers deals damage towards health<br>ザー・レフトーバー・ダミッジ・ベトウィーン・ザー・トゥー・アタカーズ・ゴー・トウォードズ・ヘルス</span></p></body></html>");
        ui->attacker4t->lower();
        ui->attacker4t->lower();
        ui->attacker6t->lower();
        ui->attacker6t->lower();
        ui->range3->lower();
        ui->range3->lower();
        ui->range4->lower();
        ui->range4->lower();
        ui->move1_2->raise();
        ui->move2_2->raise();
        ui->move2_2->raise();
        ui->move2_2->raise();

    });


    QTimer::singleShot(44500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">This attacking process repeats until you or the opponent has zero health<br>ジス・アタキング・プローセス・レピーツ・アンティル・ユー・オー・ザー・オポーネント・ハズ・ジアロー・ヘルス</span></p></body></html>");
        ui->range1->lower();
        ui->range1->lower();
        ui->range2->lower();
        ui->range2->lower();

        ui->damagedone1->lower();
        ui->damagedone1->lower();
        ui->damagedone2->lower();
        ui->damagedone2->lower();
        ui->damagedone3->lower();
        ui->damagedone3->lower();
        ui->damagedone4->lower();
        ui->damagedone4->lower();
        ui->damagetotal1->lower();
        ui->damagetotal1->lower();
        ui->damagetotal2->lower();
        ui->damagetotal2->lower();
        ui->move1_2->lower();
        ui->move2_2->lower();
        ui->move2_2->lower();
        ui->move2_2->lower();

        ui->attacker1t->lower();
        ui->attacker1t->lower();
        ui->attacker3t->lower();
        ui->attacker3t->lower();
        ui->attack1->lower();
        ui->attack1->lower();
        ui->attack2->lower();
        ui->attack2->lower();
        ui->attack3->lower();
        ui->attack3->lower();
        ui->attack4->lower();
        ui->attack4->lower();
        ui->attack5->lower();
        ui->attack5->lower();
        ui->attack6->lower();
        ui->attack6->lower();
        ui->hand1->lower();
        ui->hand1->lower();
        ui->hand2->lower();
        ui->hand2->lower();
        ui->hand3->lower();
        ui->hand3->lower();
        ui->hand4->lower();
        ui->hand4->lower();
        ui->hand5->lower();
        ui->hand5->lower();
        ui->hand6->lower();
        ui->hand6->lower();
        ui->hand7->lower();
        ui->hand7->lower();
        ui->hand8->lower();
        ui->hand8->lower();
        ui->card1->lower();
        ui->card1->lower();
        ui->card1_2->lower();
        ui->card1_2->lower();
        ui->card1_3->lower();
        ui->card1_3->lower();
        ui->card1_4->lower();
        ui->card1_4->lower();
        ui->card1_5->lower();
        ui->card1_5->lower();
        ui->circleoflife->setPixmap(QPixmap(":/images/cat.png"));
        ui->circleoflife->raise();
        ui->circleoflife->raise();

    });

    QTimer::singleShot(48500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Do your best to protect your health, you can only heal every few turns<br>ドー・ヨー・ベスト・ター・プロテクト・ヨー・ヘルス・ユー・キャン・オーンリー・ヒール・エブリー・フュー・ターンズ</span></p></body></html>");


    });

    QTimer::singleShot(52500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">You will play against ten opponents, see if you can make it to the end!<br>メーク・イット・アズ・ファー・アズ・ユー・キャン・ユー・ウィル・プレー・アゲンスト・テン・オポーネンツ・シー・イフ・ユ・キャン</span></p></body></html>");

    });

    QTimer::singleShot(56500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">If you need more help, visit the help section in the main menu<br>イフ・ユー・ニード・モー・ヘルプ・ビジット・ザー・ヘルプ・セクション・イン・ザー・メーン・メニュー</span></p></body></html>");

    });

    QTimer::singleShot(60500, this, [this]() {
        ui->tutorialtext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">Good Luck!<br>グッド・ラック</span></p></body></html>");
        ui->circleoflife->setPixmap(QPixmap(":/images/thumbsupgood.png"));

    });

    QTimer::singleShot(63500, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);

    });
}

void MainWindow::tutorialNo()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::team1select()
{
    playerCards.push_back("restore");
    team1 = true;
    ui->abilitytext_2->raise();
    ui->abilitytext_2->raise();
    ui->abilitytext_2->raise();
    ui->abilitytext_2->raise();
    ui->abilitytext_2->raise();
    ui->stackedWidget->setCurrentIndex(4);
    playerHealth = 125;
    ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");
    ui->healthplayer->setValue(playerHealth);
    ui->healthplayertitle_2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:36pt; color:#bc002d;\">Health: " + QString::number(playerHealth) + "</span></div>");
    ui->healthplayer_2->setValue(playerHealth);


}

void MainWindow::team2select()
{
    playerCards.push_back("sumo");
    team2 = true;
    ui->abilitytext->raise();
    ui->abilitytext->raise();
    ui->abilitytext->raise();
    ui->abilitytext->raise();
    ui->abilitytext->raise();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::team3select()
{
    playerCards.push_back("smith");
    team3 = true;
    ui->abilitytext_3->raise();
    ui->abilitytext_3->raise();
    ui->abilitytext_3->raise();
    ui->abilitytext_3->raise();
    ui->abilitytext_3->raise();
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::endTurnTutorial()
{
    if (attacker1Fighter == "ronin" && attacker3Fighter == "kenshi") {
        ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Great job!</span></p></body></html>");

        ui->damage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">8</span></div>");
        ui->damage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">10</span></div>");
        ui->damage4->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">5</span></div>");
        ui->damage6->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">6</span></div>");
        ui->totalDamage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">3</span></div>");
        ui->totalDamage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">4</span></div>");
        ui->attacker4card->setPixmap(QPixmap());
        ui->attacker6card->setPixmap(QPixmap());
        opponentHealth = 93;
        ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
        ui->healthopp->setValue(opponentHealth);


        QTimer::singleShot(2500, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Let us go over combat</span></p></body></html>");
        });

        QTimer::singleShot(5000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">We rolled a 4 and a 5, but because we capitalized on weaknes, the damage is doubled!</span></p></body></html>");

        });

        QTimer::singleShot(10000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">They rolled a 5 and 6 and since it is less than what we rolled they perish</span></p></body></html>");

        });

        QTimer::singleShot(15000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">The numbers in the middle is the total damage. 8-5=3, 10-6=4. So in total we did 7 damage! </span></p></body></html>");

        });

        QTimer::singleShot(20000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">You you can do more damage as well by leveling up your cards </span></p></body></html>");

        });

        QTimer::singleShot(23500, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">You you can do more damage as well by leveling up your cards </span></p></body></html>");
            ui->levelsguide->setPixmap(levels);
            ui->levelsguide->raise();
            ui->levelsguide->raise();
            ui->levelsguide->raise();
            ui->levelsguide->raise();

        });

        QTimer::singleShot(25000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Samurai is automatically level 3, the only downside is that they do not have a strength/weakness </span></p></body></html>");
        });

        QTimer::singleShot(28000, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Samurai is automatically level 3, the only downside is that they do not have a strength/weakness </span></p></body></html>");
        });

        QTimer::singleShot(33500, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Now you understand the basics! You will learn the rest of the mechanics as you go</span></p></body></html>");
            ui->levelsguide->lower();
            ui->levelsguide->lower();
            ui->levelsguide->lower();
            ui->levelsguide->lower();
            ui->levelsguide->setPixmap(QPixmap());
        });

        QTimer::singleShot(37500, this, [this]() {
            ui->maintitle_4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Good luck! Try to make it to the end!</span></p></body></html>");
        });






    }

}



void MainWindow::tutorialOpponent()
{
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 5;
    string chosen;
    attacker6 = true;
    attacker4 = true;
    attacker4Fighter = "kenshi";
    ui->attacker4card->setPixmap(kenshilevel1);
    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane.</span></p></body></html>");
    attacker6Fighter = "kyudo";
    ui->attacker6card->setPixmap(kyudolevel1);
    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane.</span></p></body></html>");
}

void MainWindow::tutorialGiveCards()
{

    cardStack = playerCards;
    container1Card = "samurai";
    container1 = true;
    ui->container1card->setPixmap(samurai);
    cardStack.erase(remove(cardStack.begin(), cardStack.end(), container1Card), cardStack.end());

    container2Card = "ronin";
    container2 = true;
    ui->container2card->setPixmap(roninlevel1);
    cardStack.erase(remove(cardStack.begin(), cardStack.end(), container2Card), cardStack.end());

    container3Card = "upgrade";
    container3 = true;
    ui->container3card->setPixmap(upgrade);
    cardStack.erase(remove(cardStack.begin(), cardStack.end(), container3Card), cardStack.end());

    container4Card = "kenshi";
    container4 = true;
    ui->container4card->setPixmap(kenshilevel1);
    cardStack.erase(remove(cardStack.begin(), cardStack.end(), container4Card), cardStack.end());

    container5Card = "diminish";
    container5 = true;
    ui->container5card->setPixmap(diminish);
    cardStack.erase(remove(cardStack.begin(), cardStack.end(), container5Card), cardStack.end());

    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
    ui->decknumbercount->setText(text);
}



void MainWindow::on_pushButton_clicked1()
{
    qDebug() << attacker1Fighter;
        if (selectedCard == "kenshi") {
        if (attacker1 == false && playerEnergy > 1) {
                ui->attacker1card->setPixmap(kenshilevel1);
                attacker1 = true;
                attacker1Fighter = "kenshi";
                selectedCard = "";
                playerEnergy = playerEnergy - 2;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        } else if (selectedCard == "samurai") {
            if (attacker1 == false && playerEnergy > 2) {
                ui->attacker1card->setPixmap(samurai);
                attacker1 = true;
                attacker1Fighter = "samurai";
                playerEnergy = playerEnergy - 3;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");


                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        } else if (selectedCard == "kyudo") {
            if (attacker1 == false && playerEnergy > 1) {
                ui->attacker1card->setPixmap(kyudolevel1);
                attacker1 = true;
                attacker1Fighter = "kyudo";
                selectedCard = "";
                playerEnergy = playerEnergy - 2;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        } else if (selectedCard == "ronin") {
            if (attacker1 == false && playerEnergy > 1) {
                ui->attacker1card->setPixmap(roninlevel1);
                attacker1 = true;
                attacker1Fighter = "ronin";
                tutorialtask1 = true;
                selectedCard = "";
                playerEnergy = playerEnergy - 2;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        }   else if (selectedCard == "hatamoto") {
            if (attacker1 == false && playerEnergy > 3) {
                ui->attacker1card->setPixmap(hatamoto);
                attacker1 = true;
                attacker1Fighter = "hatamoto";
                selectedCard = "";
                playerEnergy = playerEnergy - 4;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }

        } else if (selectedCard == "shogun") {
            if (attacker1 == false && playerEnergy > 4) {
                ui->attacker1card->setPixmap(shogun);
                attacker1 = true;
                attacker1Fighter = "shogun";
                selectedCard = "";
                playerEnergy = playerEnergy - 5;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        } else if (selectedCard == "goshi") {
            if (attacker1 == false && playerEnergy > 0) {
                ui->attacker1card->setPixmap(goshi);
                attacker1 = true;
                attacker1Fighter = "goshi";
                selectedCard = "";
                playerEnergy = playerEnergy - 1;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        } else if (selectedCard == "upgrade") {
            if (attacker1 == true && playerEnergy > 0) {




                if (attacker1Fighter == "kenshi") {

                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "kenshilevel2";
                    ui->attacker1card->setPixmap(kenshilevel2);
                    selectedCard = "";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 2!</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                    playerEnergy--;
                    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else if (attacker1Fighter == "kenshilevel2") {
                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "kenshilevel3";
                    ui->attacker1card->setPixmap(kenshilevel3);
                    selectedCard = "";
                     ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 3!</span></p></body></html>");
                     ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                     playerEnergy--;
                     ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else if (attacker1Fighter == "ronin") {
                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "roninlevel2";
                    selectedCard = "";
                    ui->attacker1card->setPixmap(roninlevel2);
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 2!</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                    playerEnergy--;
                    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else if (attacker1Fighter == "roninlevel2") {
                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "roninlevel3";
                    selectedCard = "";
                    ui->attacker1card->setPixmap(roninlevel3);
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 3!</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                    playerEnergy--;
                    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else if (attacker1Fighter == "kyudo") {
                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "kyudolevel2";
                    selectedCard = "";
                    ui->attacker1card->setPixmap(kyudolevel2);
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 2!</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                    playerEnergy--;
                    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else if (attacker1Fighter == "kyudolevel2") {
                    cardStack.push_back("upgrade");
                    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                    ui->decknumbercount->setText(text);
                    attacker1Fighter = "kyudolevel3";
                    selectedCard = "";
                    ui->attacker1card->setPixmap(kyudolevel3);
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 3!</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                    playerEnergy--;
                    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                    if (alreadyClicked1 == true) {
                        container1 = false;
                        ui->container1card->move(originalPos1.x(), originalPos1.y());
                        alreadyClicked1 = false;
                        ui->container1card->setPixmap(QPixmap());
                        container1Card = "";
                    } else if (alreadyClicked2 == true) {
                        container2 = false;
                        ui->container2card->move(originalPos2.x(), originalPos2.y());
                        alreadyClicked2 = false;
                        ui->container2card->setPixmap(QPixmap());
                        container2Card = "";
                    } else if (alreadyClicked3 == true) {
                        container3 = false;
                        ui->container3card->move(originalPos3.x(), originalPos3.y());
                        alreadyClicked3 = false;
                        ui->container3card->setPixmap(QPixmap());
                        container3Card = "";
                    } else if (alreadyClicked4 == true) {
                        container4 = false;
                        ui->container4card->move(originalPos4.x(), originalPos4.y());
                        ui->container4card->setPixmap(QPixmap());
                        container4Card = "";
                    } else if (alreadyClicked5 == true) {
                        container5 = false;
                        ui->container5card->move(originalPos5.x(), originalPos5.y());
                        ui->container5card->setPixmap(QPixmap());
                        container5Card = "";
                    }

                } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be upgraded</span></p></body></html>");
            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");

        } else if (selectedCard == "sumo") {
            if (attacker1 == false && playerEnergy > 2) {
                ui->attacker1card->setPixmap(sumo);
                attacker1 = true;
                attacker1Fighter = "sumo";
                selectedCard = "";
                playerEnergy = playerEnergy - 3;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-20</span></p></body></html>");



                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            }
        }


}

void MainWindow::on_pushButton_clicked2()
{
    qDebug() << attacker2Fighter;
    if (selectedCard == "kenshi") {
        if (attacker2 == false && playerEnergy > 1) {
            ui->attacker2card->setPixmap(kenshilevel1);
            attacker2 = true;
            attacker2Fighter = "kenshi";
            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "samurai") {
        if (attacker2 == false && playerEnergy > 2) {
            ui->attacker2card->setPixmap(samurai);
            attacker2 = true;
            attacker2Fighter = "samurai";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");


            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "kyudo") {
        if (attacker2 == false && playerEnergy > 1) {
            ui->attacker2card->setPixmap(kyudolevel1);
            attacker2 = true;
            attacker2Fighter = "kyudo";
            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "ronin") {
        if (attacker2 == false && playerEnergy > 1) {
            ui->attacker2card->setPixmap(roninlevel1);
            attacker2 = true;
            attacker2Fighter = "ronin";

            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    }   else if (selectedCard == "hatamoto") {
        if (attacker2 == false && playerEnergy > 3) {
            ui->attacker2card->setPixmap(hatamoto);
            attacker2 = true;
            attacker2Fighter = "hatamoto";
            selectedCard = "";
            playerEnergy = playerEnergy - 4;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }

    } else if (selectedCard == "shogun") {
        if (attacker2 == false && playerEnergy > 4) {
            ui->attacker2card->setPixmap(shogun);
            attacker2 = true;
            attacker2Fighter = "shogun";
            selectedCard = "";
            playerEnergy = playerEnergy - 5;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "goshi") {
        if (attacker2 == false && playerEnergy > 0) {
            ui->attacker2card->setPixmap(goshi);
            attacker2 = true;
            attacker2Fighter = "goshi";
            selectedCard = "";
            playerEnergy = playerEnergy - 1;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }

    } else if (selectedCard == "upgrade") {
        if (attacker2 == true && playerEnergy > 0) {


            if (attacker2Fighter == "kenshi") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "kenshilevel2";
                ui->attacker2card->setPixmap(kenshilevel2);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker2Fighter == "kenshilevel2") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "kenshilevel3";
                ui->attacker2card->setPixmap(kenshilevel3);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker2Fighter == "ronin") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "roninlevel2";
                selectedCard = "";
                ui->attacker2card->setPixmap(roninlevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker2Fighter == "roninlevel2") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "roninlevel3";
                selectedCard = "";
                ui->attacker2card->setPixmap(roninlevel3);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker2Fighter == "kyudo") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "kyudolevel2";
                selectedCard = "";
                ui->attacker2card->setPixmap(kyudolevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker2Fighter == "kyudolevel2") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker2Fighter = "kyudolevel3";
                selectedCard = "";
                ui->attacker2card->setPixmap(kyudolevel3);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be upgraded</span></p></body></html>");
        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");

    } else if (selectedCard == "sumo") {
        if (attacker2 == false && playerEnergy > 2) {
            ui->attacker2card->setPixmap(sumo);
            attacker2 = true;
            attacker2Fighter = "sumo";
            selectedCard = "";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-20</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    }




}

void MainWindow::on_pushButton_clicked3()
{
    qDebug() << attacker3Fighter;

    if (selectedCard == "kenshi") {
        if (attacker3 == false && playerEnergy > 1) {
            ui->attacker3card->setPixmap(kenshilevel1);
            attacker3 = true;
            attacker3Fighter = "kenshi";
            tutorialtask2 = true;
            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "samurai") {
        if (attacker3 == false && playerEnergy > 2) {
            ui->attacker3card->setPixmap(samurai);
            attacker3 = true;
            attacker3Fighter = "samurai";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");


            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "kyudo") {
        if (attacker3 == false && playerEnergy > 1) {
            ui->attacker3card->setPixmap(kyudolevel1);
            attacker3 = true;
            attacker3Fighter = "kyudo";
            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "ronin") {
        if (attacker3 == false && playerEnergy > 1) {
            ui->attacker3card->setPixmap(roninlevel1);
            attacker3 = true;
            attacker3Fighter = "ronin";
            selectedCard = "";
            playerEnergy = playerEnergy - 2;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }

    }   else if (selectedCard == "hatamoto") {
        if (attacker3 == false && playerEnergy > 3) {
            ui->attacker3card->setPixmap(hatamoto);
            attacker3 = true;
            attacker3Fighter = "hatamoto";
            selectedCard = "";
            playerEnergy = playerEnergy - 4;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }

    } else if (selectedCard == "shogun") {
        if (attacker3 == false && playerEnergy > 4) {
            ui->attacker3card->setPixmap(shogun);
            attacker3 = true;
            attacker3Fighter = "shogun";
            selectedCard = "";
            playerEnergy = playerEnergy - 5;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    } else if (selectedCard == "goshi") {
        if (attacker3 == false && playerEnergy > 0) {
            ui->attacker3card->setPixmap(goshi);
            attacker3 = true;
            attacker3Fighter = "goshi";
            selectedCard = "";
            playerEnergy = playerEnergy - 1;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }

    } else if (selectedCard == "upgrade") {
        if (attacker3 == true && playerEnergy > 0) {

            if (attacker3Fighter == "kenshi") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "kenshilevel2";
                ui->attacker3card->setPixmap(kenshilevel2);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker3Fighter == "kenshilevel2") {

                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "kenshilevel3";
                ui->attacker3card->setPixmap(kenshilevel3);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker3Fighter == "ronin") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "roninlevel2";
                selectedCard = "";
                ui->attacker3card->setPixmap(roninlevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker3Fighter == "roninlevel2") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "roninlevel3";
                selectedCard = "";
                ui->attacker3card->setPixmap(roninlevel3);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker3Fighter == "kyudo") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "kyudolevel2";
                selectedCard = "";
                ui->attacker3card->setPixmap(kyudolevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 2!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker3Fighter == "kyudolevel2") {
                cardStack.push_back("upgrade");
                QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
                ui->decknumbercount->setText(text);
                attacker3Fighter = "kyudolevel3";
                selectedCard = "";
                ui->attacker3card->setPixmap(kyudolevel3);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo had been upgraded to level 3!</span></p></body></html>");
                ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                playerEnergy--;
                ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be upgraded</span></p></body></html>");
        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");

    } else if (selectedCard == "sumo") {
        if (attacker3 == false && playerEnergy > 2) {
            ui->attacker3card->setPixmap(sumo);
            attacker3 = true;
            attacker3Fighter = "sumo";
            selectedCard = "";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-20</span></p></body></html>");



            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        }
    }






}

void MainWindow::on_pushButton_clicked4()
{
    if (selectedCard == "expell") {
        if (attacker4 == true && playerEnergy > 2) {
            ui->attacker4card->setPixmap(kenshilevel1);
            ui->attacker4card->setPixmap(QPixmap());
            attacker4 = false;
            attacker4Fighter = "";
            selectedCard = "";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            cardStack.push_back("expell");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);
            ui->damagerange4->clear();
            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">this lane does not have a card or not enough energy</span></p></body></html>");
    } else if (selectedCard == "diminish") {
        if (attacker4 && playerEnergy > 0 && (attacker4Fighter != "kenshi" && attacker4Fighter != "samurai" && attacker4Fighter != "ronin" && attacker4Fighter != "kyudo")) {
            playerEnergy--;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            cardStack.push_back("diminish");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);

            if (attacker4Fighter == "kenshilevel2") {
                attacker4Fighter = "kenshi";
                ui->attacker4card->setPixmap(kenshilevel1);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker4Fighter == "kenshilevel3") {
                attacker4Fighter = "kenshilevel2";
                ui->attacker4card->setPixmap(kenshilevel2);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker4Fighter == "roninlevel2") {
                attacker4Fighter = "ronin";
                selectedCard = "";
                ui->attacker4card->setPixmap(roninlevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker4Fighter == "roninlevel3") {
                attacker4Fighter = "roninlevel2";
                selectedCard = "";
                ui->attacker4card->setPixmap(roninlevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker4Fighter == "kyudolevel2") {
                attacker4Fighter = "kyudo";
                selectedCard = "";
                ui->attacker4card->setPixmap(kyudolevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker4Fighter == "kyudolevel3") {
                attacker4Fighter = "kyudolevel2";
                selectedCard = "";
                ui->attacker4card->setPixmap(kyudolevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been upgraded to level 2!</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be downgraded</span></p></body></html>");
        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");
    }

}

void MainWindow::on_pushButton_clicked5()
{
    if (selectedCard == "expell") {
        if (attacker5 == true && playerEnergy > 2) {
            ui->attacker5card->setPixmap(kenshilevel1);
            ui->attacker5card->setPixmap(QPixmap());
            attacker5 = false;
            attacker5Fighter = "";
            selectedCard = "";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            ui->damagerange5->clear();
            cardStack.push_back("expell");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);

            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">this lane does not have a card or not enough energy</span></p></body></html>");
    } else if (selectedCard == "diminish") {
        if (attacker5 && playerEnergy > 0 && (attacker5Fighter != "kenshi" && attacker5Fighter != "samurai" && attacker5Fighter != "ronin" && attacker5Fighter != "kyudo")) {
            playerEnergy--;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            cardStack.push_back("diminish");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);

            if (attacker5Fighter == "kenshilevel2") {
                attacker5Fighter = "kenshi";
                ui->attacker5card->setPixmap(kenshilevel1);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker5Fighter == "kenshilevel3") {
                attacker5Fighter = "kenshilevel2";
                ui->attacker5card->setPixmap(kenshilevel2);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker5Fighter == "roninlevel2") {
                attacker5Fighter = "ronin";
                selectedCard = "";
                ui->attacker5card->setPixmap(roninlevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker5Fighter == "roninlevel3") {
                attacker5Fighter = "roninlevel2";
                selectedCard = "";
                ui->attacker5card->setPixmap(roninlevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker5Fighter == "kyudolevel2") {
                attacker5Fighter = "kyudo";
                selectedCard = "";
                ui->attacker5card->setPixmap(kyudolevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker5Fighter == "kyudolevel3") {
                attacker5Fighter = "kyudolevel2";
                selectedCard = "";
                ui->attacker5card->setPixmap(kyudolevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been upgraded to level 2!</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be downgraded</span></p></body></html>");
        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");
    }



}

void MainWindow::on_pushButton_clicked6()
{
    if (selectedCard == "expell") {
        if (attacker6 == true && playerEnergy > 2) {
            ui->attacker6card->setPixmap(kenshilevel1);
            ui->attacker6card->setPixmap(QPixmap());
            attacker6 = false;
            attacker6Fighter = "";
            selectedCard = "";
            playerEnergy = playerEnergy - 3;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            cardStack.push_back("expell");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);
            ui->damagerange6->clear();

            if (alreadyClicked1 == true) {
                container1 = false;
                ui->container1card->move(originalPos1.x(), originalPos1.y());
                alreadyClicked1 = false;
                ui->container1card->setPixmap(QPixmap());
                container1Card = "";
            } else if (alreadyClicked2 == true) {
                container2 = false;
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                ui->container2card->setPixmap(QPixmap());
                container2Card = "";
            } else if (alreadyClicked3 == true) {
                container3 = false;
                ui->container3card->move(originalPos3.x(), originalPos3.y());
                alreadyClicked3 = false;
                ui->container3card->setPixmap(QPixmap());
                container3Card = "";
            } else if (alreadyClicked4 == true) {
                container4 = false;
                ui->container4card->move(originalPos4.x(), originalPos4.y());
                ui->container4card->setPixmap(QPixmap());
                container4Card = "";
            } else if (alreadyClicked5 == true) {
                container5 = false;
                ui->container5card->move(originalPos5.x(), originalPos5.y());
                ui->container5card->setPixmap(QPixmap());
                container5Card = "";
            }

        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">this lane does not have a card or not enough energy</span></p></body></html>");
    } else if (selectedCard == "diminish") {
        if (attacker6 && playerEnergy > 0 && (attacker6Fighter != "kenshi" && attacker6Fighter != "samurai" && attacker6Fighter != "ronin" && attacker6Fighter != "kyudo")) {
            playerEnergy--;
            ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
            cardStack.push_back("diminish");
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);

            if (attacker6Fighter == "kenshilevel2") {
                attacker6Fighter = "kenshi";
                ui->attacker6card->setPixmap(kenshilevel1);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker6Fighter == "kenshilevel3") {
                attacker6Fighter = "kenshilevel2";
                ui->attacker6card->setPixmap(kenshilevel2);
                selectedCard = "";
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kenshi has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker6Fighter == "roninlevel2") {
                attacker6Fighter = "ronin";
                selectedCard = "";
                ui->attacker6card->setPixmap(roninlevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker6Fighter == "roninlevel3") {
                attacker6Fighter = "roninlevel2";
                selectedCard = "";
                ui->attacker6card->setPixmap(roninlevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">ronin has been downgraded to level 2!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker6Fighter == "kyudolevel2") {
                attacker6Fighter = "kyudo";
                selectedCard = "";
                ui->attacker6card->setPixmap(kyudolevel1);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been downgraded to level 1!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else if (attacker6Fighter == "kyudolevel3") {
                attacker6Fighter = "kyudolevel2";
                selectedCard = "";
                ui->attacker6card->setPixmap(kyudolevel2);
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">kyudo has been upgraded to level 2!</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                if (alreadyClicked1 == true) {
                    container1 = false;
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                    ui->container1card->setPixmap(QPixmap());
                    container1Card = "";
                } else if (alreadyClicked2 == true) {
                    container2 = false;
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                    ui->container2card->setPixmap(QPixmap());
                    container2Card = "";
                } else if (alreadyClicked3 == true) {
                    container3 = false;
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                    ui->container3card->setPixmap(QPixmap());
                    container3Card = "";
                } else if (alreadyClicked4 == true) {
                    container4 = false;
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    ui->container4card->setPixmap(QPixmap());
                    container4Card = "";
                } else if (alreadyClicked5 == true) {
                    container5 = false;
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    ui->container5card->setPixmap(QPixmap());
                    container5Card = "";
                }

            } else
                ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">card cannot be downgraded</span></p></body></html>");
        } else
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">there is no active card here</span></p></body></html>");
    }



}

void MainWindow::giveCards()
{
    if (team3 == true) {
        playerEnergy = 6;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
    } else {
        playerEnergy = 5;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

    }


    while (true) {
        if (cardStack.empty() || (container1 && container2 && container3 && container4 && container5)) {
            break;
        }

        int randomCardAlgo = rand() % cardStack.size();
        string randomCardChosen = cardStack[randomCardAlgo];
        QLabel* containerCardLabel = nullptr;
        bool* containerFlag = nullptr;
        string* containerCard = nullptr;

        if (!container1) {
            containerCardLabel = ui->container1card;
            containerFlag = &container1;
            containerCard = &container1Card;
        } else if (!container2) {
            containerCardLabel = ui->container2card;
            containerFlag = &container2;
            containerCard = &container2Card;
        } else if (!container3) {
            containerCardLabel = ui->container3card;
            containerFlag = &container3;
            containerCard = &container3Card;
        } else if (!container4) {
            containerCardLabel = ui->container4card;
            containerFlag = &container4;
            containerCard = &container4Card;
        } else if (!container5) {
            containerCardLabel = ui->container5card;
            containerFlag = &container5;
            containerCard = &container5Card;
        }

        if (containerCardLabel) {
            if (randomCardChosen == "ronin") {
                containerCardLabel->setPixmap(roninlevel1);
            } else if (randomCardChosen == "kenshi") {
                containerCardLabel->setPixmap(kenshilevel1);
            } else if (randomCardChosen == "kyudo") {
                containerCardLabel->setPixmap(kyudolevel1);
            } else if (randomCardChosen == "samurai") {
                containerCardLabel->setPixmap(samurai);
            } else if (randomCardChosen == "strike") {
                containerCardLabel->setPixmap(strike);
            } else if (randomCardChosen == "upgrade") {
                containerCardLabel->setPixmap(upgrade);
            } else if (randomCardChosen == "diminish") {
                containerCardLabel->setPixmap(diminish);
            } else if (randomCardChosen == "wager") {
                containerCardLabel->setPixmap(wager);
            } else if (randomCardChosen == "expell") {
                containerCardLabel->setPixmap(expell);
            } else if (randomCardChosen == "shogun") {
                containerCardLabel->setPixmap(shogun);
            } else if (randomCardChosen == "hatamoto") {
                containerCardLabel->setPixmap(hatamoto);
            } else if (randomCardChosen == "goshi") {
                containerCardLabel->setPixmap(goshi);
            } else if (randomCardChosen == "fortify") {
                containerCardLabel->setPixmap(fortify);
            } else if (randomCardChosen == "blessing") {
                containerCardLabel->setPixmap(blessing);
            } else if (randomCardChosen == "smith") {
                containerCardLabel->setPixmap(smith);
            } else if (randomCardChosen == "restore") {
                containerCardLabel->setPixmap(restore);
            } else if (randomCardChosen == "sumo") {
                containerCardLabel->setPixmap(sumo);
            }

            *containerCard = randomCardChosen;
            *containerFlag = true;

            if (randomCardAlgo >= 0 && randomCardAlgo < cardStack.size()) {
                cardStack.erase(cardStack.begin() + randomCardAlgo);
            }
        }
    }

    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
    ui->decknumbercount->setText(text);
}

void MainWindow::tutorialProcess()
{
    level = 0;
    playerEnergy = 5;
    ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Welcome to the tutorial! My name is aki!</span></p></body></html>");

    ui->container1->setVisible(false);
    ui->container2->setVisible(false);
    ui->container3->setVisible(false);
    ui->container4->setVisible(false);
    ui->container5->setVisible(false);
    ui->attacker1->setVisible(false);
    ui->attacker2->setVisible(false);
    ui->attacker3->setVisible(false);
    ui->attacker4->setVisible(false);
    ui->attacker5->setVisible(false);
    ui->attacker6->setVisible(false);
    ui->deckcontainer->setVisible(false);
    ui->deckslot->setVisible(false);
    ui->decknumbercount->setVisible(false);
    ui->healthplayer->setVisible(false);
    ui->healthplayertitle->setVisible(false);
    ui->circle->setVisible(false);


    int deckSize = playerCards.size();
    QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(deckSize);
    ui->decknumbercount->setText(text);
    QTimer::singleShot(0, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Welcome to the tutorial! My name is aki, I will show you around!</span></p></body></html>");
    });

    QTimer::singleShot(5000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">This is the layout of the battlefield!</span></p></body></html>");
        ui->container1->setVisible(true);
        ui->container2->setVisible(true);
        ui->container3->setVisible(true);
        ui->container4->setVisible(true);
        ui->container5->setVisible(true);
        ui->attacker1->setVisible(true);
        ui->attacker2->setVisible(true);
        ui->attacker3->setVisible(true);
        ui->attacker4->setVisible(true);
        ui->attacker5->setVisible(true);
        ui->attacker6->setVisible(true);
        ui->deckcontainer->setVisible(true);
        ui->deckslot->setVisible(true);
        ui->decknumbercount->setVisible(true);

    });

    QTimer::singleShot(2500, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Right here is your deck, currently you have 7 cards as shown</span></p></body></html>");
        ui->circle->setVisible(true);
    });
    QTimer::singleShot(3500, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Your deck can have up to 20 cards, you will unlock more as you continue</span></p></body></html>");
    });
    QTimer::singleShot(4000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Well let's start a quick game to get you on your way</span></p></body></html>");
    });
    QTimer::singleShot(5000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Your opponent will always go first, lets see what they do!</span></p></body></html>");
        ui->circle->setVisible(false);
        tutorialOpponent();
    });
    QTimer::singleShot(6000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Looks like they played kenshi and kyudo!</span></p></body></html>");
    });
    QTimer::singleShot(7000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">You can see what cards they play specifically by looking at the console here</span></p></body></html>");
    });
    QTimer::singleShot(8000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">You can see what cards they play specifically by looking at the console here</span></p></body></html>");
    });
    QTimer::singleShot(9000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Now it is our turn! Let us see what cards we get!</span></p></body></html>");
        tutorialGiveCards();
    });
    QTimer::singleShot(10000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Not a bad hand of cards!</span></p></body></html>");
    });
    QTimer::singleShot(11000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Before we play anything, you must understand the art of war...</span></p></body></html>");
        ui->artofwar->raise();
        ui->artofwar->raise();
        ui->artofwar->raise();
        ui->artofwar->raise();
        ui->artofwar->raise();
        ui->artofwar->raise();
        ui->artofwar->setPixmap(artOfWar);
    });
    QTimer::singleShot(13000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">As shown, every card has a strength. We must use this to our advantage!</span></p></body></html>");
    });
    QTimer::singleShot(15000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">The samurai class does not have a strength/weakness though</span></p></body></html>");
    });
    QTimer::singleShot(15000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Samurai can not be upgraded either, we will go over upgrading later</span></p></body></html>");
    });
    QTimer::singleShot(17000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">So looks like they played Kenshi and Kyudo in the left and right lane</span></p></body></html>");
        ui->artofwar->lower();
        ui->artofwar->lower();
        ui->artofwar->lower();
        ui->artofwar->lower();
        ui->artofwar->lower();
        ui->artofwar->setPixmap(QPixmap());
    });
    QTimer::singleShot(19000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">We need to defend these lanes otherwise they will be ungaurded and we take damage!</span></p></body></html>");
    });
    QTimer::singleShot(21000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Here is our health, we must do our best to defend it! We can only heal so often..</span></p></body></html>");
        ui->healthplayer->setVisible(true);
        ui->healthplayertitle->setVisible(true);
    });
    QTimer::singleShot(23000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">We need to defend these lanes otherwise they will be left ungaurded and we take damage!</span></p></body></html>");
    });
    QTimer::singleShot(25000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Drag the appropiate cards to the left and right lane</span></p></body></html>");
        ui->arrowone->raise();
        ui->arrowone->raise();
        ui->arrowone->raise();
        ui->arrowone->raise();
        ui->arrowone->raise();
        ui->arrowtwo->raise();
        ui->arrowtwo->raise();
        ui->arrowtwo->raise();
        ui->arrowtwo->raise();
        ui->arrowtwo->raise();
       ui->arrowone->setPixmap(arrow);
       ui->arrowtwo->setPixmap(arrow);
    });

    QTimer::singleShot(26000, this, [this]() {
        ui->toptext->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">Drag the appropiate cards to the left and right lane</span></p></body></html>");
        ui->arrowone->lower();
        ui->arrowone->lower();
        ui->arrowone->lower();
        ui->arrowone->lower();
        ui->arrowone->lower();
        ui->arrowtwo->lower();
        ui->arrowtwo->lower();
        ui->arrowtwo->lower();
        ui->arrowtwo->lower();
        ui->arrowtwo->lower();
       ui->arrowone->setPixmap(QPixmap());
       ui->arrowtwo->setPixmap(QPixmap());
    });
}



void MainWindow::endTurnBetter1()
{
    ui->gifslot1->raise();
    ui->gifslot1->raise();
    ui->gifslot1->raise();
    ui->gifslot1->raise();
    ui->gifslot4->raise();
    ui->gifslot4->raise();
    ui->gifslot4->raise();
    ui->gifslot4->raise();

    QTimer::singleShot(1000, this, [this]() {
        ui->gifslot1->lower();
        ui->gifslot1->lower();
        ui->gifslot1->lower();
        ui->gifslot1->lower();
        ui->gifslot4->lower();
        ui->gifslot4->lower();
        ui->gifslot4->lower();
        ui->gifslot4->lower();
        ui->gifslot1->setMovie(nullptr);
        ui->gifslot4->setMovie(nullptr);
    });

    QMovie *skull = new QMovie(":/images/skull.gif");
    //assigning damage for player card in slot 1
    int damage1;
    if (attacker1 == true) {
        if (attacker1Fighter == "kenshi" || attacker1Fighter == "ronin" || attacker1Fighter == "kyudo") {
            damageGenerated1 = rand() % 6 + 1;
            qDebug() << "generating damage for kenshi/ronin/kyudo";
        } else if (attacker1Fighter == "kenshilevel2" || attacker1Fighter == "kyudolevel2" || attacker1Fighter == "roninlevel2") {
            damageGenerated1 = rand() % 7 + 2;
            qDebug() << "generating damage for level 2";
        } else if (attacker1Fighter == "kenshilevel3" || attacker1Fighter == "kyudolevel3" || attacker1Fighter == "roninlevel3") {
            damageGenerated1 = rand() % 8 + 3;
            qDebug() << "generating damage for level 3";
        } else if (attacker1Fighter == "samurai") {
            damageGenerated1 = rand() % 10 + 1;
            qDebug() << "generating damage for samurai";
        } else if (attacker1Fighter == "goshi") {
            damageGenerated1 = rand() % 3 + 1;
            qDebug() << "generating damage for goshi";
        } else if (attacker1Fighter == "hatamoto") {
            damageGenerated1 = rand() % 15 + 1;
            qDebug() << "generating damage for hatamoto";
        } else if (attacker1Fighter == "shogun") {
            damageGenerated1 = rand() % 10 + 1;
            qDebug() << "generating damage for shogun";
        } else if (attacker1Fighter == "sumo") {
            damageGenerated1 = rand() % 20 + 1;
            qDebug() << "generating damage between 1 and 20 for sumo";
        }

    } else {
        damageGenerated1 = 0;
    }

    //assigning damage for opponent card in slot 4
    if (attacker4 == true) {
        if (attacker4Fighter == "kenshi" || attacker4Fighter == "ronin" || attacker4Fighter == "kyudo") {
            damageGenerated4 = rand() % 6 + 1;
        } else if (attacker4Fighter == "kenshilevel2" || attacker4Fighter == "kyudolevel2" || attacker4Fighter == "roninlevel2") {
            damageGenerated4 = rand() % 7 + 2;
        } else if (attacker4Fighter == "kenshilevel3" || attacker4Fighter == "kyudolevel3" || attacker4Fighter =="roninlevel3") {
            damageGenerated4 = rand() % 8 + 3;
        } else if (attacker4Fighter == "samurai") {
            damageGenerated4 = rand() % 10 + 1;
        } else if (attacker4Fighter == "goshi") {
            damageGenerated4 = rand() % 3 + 1;
        } else if (attacker4Fighter == "hatamoto") {
            damageGenerated4 = rand() % 15 + 1;
        } else if (attacker4Fighter == "shogun") {
            damageGenerated4 = rand() % 10 + 1;
        }

    } else {
        damageGenerated4 = 0;
    }

    //kenshi weakness player
    if ((attacker1Fighter == "kenshi" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "kenshilevel3")
    && (attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated4;
        damageGenerated4 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated4;
        ui->double4->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness player
    } else if ((attacker1Fighter == "ronin" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "roninlevel3")
    && (attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2" || attacker4Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated4;
        damageGenerated4 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated4;
        ui->double4->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness player
    } else if ((attacker1Fighter == "kyudo" || attacker1Fighter == "kyudolevel2" || attacker1Fighter == "kyudolevel3")
    && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated4;
        damageGenerated4 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated4;
        ui->double4->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker1 == true && attacker1Fighter != "shogun")
    && (attacker4Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated4;
        damageGenerated4 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated4;
        ui->double4->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }

    //kenshi weakness opponent
    else if ((attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "kenshilevel3")
        && (attacker1Fighter == "ronin" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated1;
        damageGenerated1 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated1;
        ui->double1->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness opponent
    } else if ((attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "roninlevel3")
        && (attacker1Fighter == "kyudo" || attacker1Fighter == "kyudolevel2" || attacker1Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated1;
        damageGenerated1 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated1;
        ui->double1->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness opponent
    } else if ((attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2" || attacker4Fighter == "kyudolevel3")
        && (attacker1Fighter == "kenshi" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated1;
        damageGenerated1 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated1;
        ui->double1->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker4 == true && attacker4Fighter != "shogun")
        && (attacker1Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated1;
        damageGenerated1 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated1;
        ui->double1->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }


    if (iswager == true) {
        qDebug() << "WAGER DAMAGE DOUBLED";
        damageGenerated1*=2;
        damageGenerated4*=2;
    }

    //team2 attack bonus
    if (team2 == true && attacker1 == true) {
        damageGenerated1++;
    }
    //evaluating damage
    int totalDamage1 = damageGenerated1 - damageGenerated4;

    //updating damage labels
    ui->damage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated1) + "</span></div>");
    ui->damage4->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated4) + "</span></div>");
    ui->totalDamage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(totalDamage1) + "</span></div>");


    //assigning health damage to player and updating labels
    if (totalDamage1 > 0) {
        opponentHealth = opponentHealth - totalDamage1;
        ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
        ui->healthopp->setValue(opponentHealth);
        if(attacker4 == true) {
            attacker4Fighter = "";
            attacker4 = false;
            ui->attacker4card->setPixmap(QPixmap());
            ui->gifslot4->setMovie(skull);
            ui->damagerange4->clear();
            skull->start();

        }

    } else if (totalDamage1 < 0) {
        playerHealth = playerHealth + totalDamage1;
        ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");
        ui->healthplayer->setValue(playerHealth);
        if (attacker1 == true) {
            // Assuming attacker1Fighter is a string
            std::string modifiedString = attacker1Fighter;

            // Remove "level2" if it exists in the string
            size_t pos = modifiedString.find("level2");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level2"
            }

            // Remove "level3" if it exists in the string
            pos = modifiedString.find("level3");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level3"
            }

            if(revertgoshi1 == true) {
                modifiedString = "goshi";
                revertgoshi1 = false;
            }

            // Push the modified string back into the cardStack
            cardStack.push_back(modifiedString);

            attacker1Fighter = "";
            ui->damagerange1->clear();
            attacker1 = false;
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);
            ui->attacker1card->setPixmap(QPixmap());
            ui->gifslot1->setMovie(skull);
            skull->start();
        }
    }
}

void MainWindow::endTurnBetter2()
{
    ui->gifslot2->raise();
    ui->gifslot2->raise();
    ui->gifslot2->raise();
    ui->gifslot2->raise();
    ui->gifslot5->raise();
    ui->gifslot5->raise();
    ui->gifslot5->raise();
    ui->gifslot5->raise();

    QTimer::singleShot(1000, this, [this]() {
        ui->gifslot2->lower();
        ui->gifslot2->lower();
        ui->gifslot2->lower();
        ui->gifslot2->lower();
        ui->gifslot5->lower();
        ui->gifslot5->lower();
        ui->gifslot5->lower();
        ui->gifslot5->lower();
        ui->gifslot2->setMovie(nullptr);
        ui->gifslot5->setMovie(nullptr);
    });


    QMovie *skull = new QMovie(":/images/skull.gif");
    //assigning damage for player card in slot 2

    if (attacker2 == true) {
        if (attacker2Fighter == "kenshi" || attacker2Fighter == "ronin" || attacker2Fighter == "kyudo") {
            damageGenerated2 = rand() % 6 + 1;
        } else if (attacker2Fighter == "kenshilevel2" || attacker2Fighter == "kyudolevel2" || attacker2Fighter == "roninlevel2") {
            damageGenerated2 = rand() % 7 + 2;
        } else if (attacker2Fighter == "kenshilevel3" || attacker2Fighter == "kyudolevel3" || attacker2Fighter == "roninlevel3") {
            damageGenerated2 = rand() % 8 + 3;
        } else if (attacker2Fighter == "samurai") {
            damageGenerated2 = rand() % 10 + 1;
        } else if (attacker2Fighter == "goshi") {
            damageGenerated2 = rand() % 3 + 1;
        } else if (attacker2Fighter == "hatamoto") {
            damageGenerated2 = rand() % 15 + 1;
        } else if (attacker2Fighter == "shogun") {
            damageGenerated2 = rand() % 10 + 1;
        } else if (attacker2Fighter == "sumo") {
            damageGenerated2 = rand() % 20 + 1;
        }

    } else {
        damageGenerated2 = 0;
    }

    //assigning damage for opponent card in slot 4
    if (attacker5 == true) {
        if (attacker5Fighter == "kenshi" || attacker5Fighter == "ronin" || attacker5Fighter == "kyudo") {
            damageGenerated5 = rand() % 6 + 1;
        } else if (attacker5Fighter == "kenshilevel2" || attacker5Fighter == "kyudolevel2" || attacker5Fighter == "roninlevel2") {
            damageGenerated5 = rand() % 7 + 2;
        } else if (attacker5Fighter == "kenshilevel3" || attacker5Fighter == "kyudolevel3" || attacker5Fighter == "roninlevel3") {
            damageGenerated5 = rand() % 8 + 3;
        } else if (attacker5Fighter == "samurai") {
            damageGenerated5 = rand() % 10 + 1;
        } else if (attacker5Fighter == "goshi") {
            damageGenerated5 = rand() % 3 + 1;
        } else if (attacker5Fighter == "hatamoto") {
            damageGenerated5 = rand() % 15 + 1;
        } else if (attacker5Fighter == "shogun") {
            damageGenerated5 = rand() % 10 + 1;
        }

    } else {
        damageGenerated5 = 0;
    }

    //kenshi weakness player
    if ((attacker2Fighter == "kenshi" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "kenshilevel3")
    && (attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated5;
        damageGenerated5 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated5;
        ui->double5->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness player
    } else if ((attacker2Fighter == "ronin" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "roninlevel3")
    && (attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2" || attacker5Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated5;
        damageGenerated5 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated5;
        ui->double5->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness player
    } else if ((attacker2Fighter == "kyudo" || attacker2Fighter == "kyudolevel2" || attacker2Fighter == "kyudolevel3")
    && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated5;
        damageGenerated5 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated5;
        ui->double5->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker2 == true && attacker2Fighter != "shogun")
    && (attacker5Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated5;
        damageGenerated5 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated5;
        ui->double5->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }

    //kenshi weakness opponent
    else if ((attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "kenshilevel3")
        && (attacker2Fighter == "ronin" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated2;
        damageGenerated2 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated2;
        ui->double2->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness opponent
    } else if ((attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "roninlevel3")
        && (attacker2Fighter == "kyudo" || attacker2Fighter == "kyudolevel2" || attacker2Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated2;
        damageGenerated2 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated2;
        ui->double2->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness opponent
    } else if ((attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2" || attacker5Fighter == "kyudolevel3")
        && (attacker2Fighter == "kenshi" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated2;
        damageGenerated2 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated2;
        ui->double2->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker5 == true && attacker5Fighter != "shogun")
        && (attacker2Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated2;
        damageGenerated2 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated2;
        ui->double2->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }


    if (iswager == true) {
        qDebug() << "WAGER DAMAGE DOUBLED";
        damageGenerated2*=2;
        damageGenerated5*=2;
    }

    //team2 attack bonus
    if (team2 == true && attacker2 == true) {
        damageGenerated2++;
    }

    //evaluating damage
    int totaldamage2 = damageGenerated2 - damageGenerated5;

    //updating damage labels
    ui->damage2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated2) + "</span></div>");
    ui->damage5->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated5) + "</span></div>");
    ui->totalDamage2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(totaldamage2) + "</span></div>");


    //assigning health damage to player and updating labels
    if (totaldamage2 > 0) {
        opponentHealth = opponentHealth - totaldamage2;
        ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
        ui->healthopp->setValue(opponentHealth);
        if(attacker5 == true) {
            attacker5Fighter = "";
            attacker5 = false;
            ui->damagerange5->clear();
            ui->attacker5card->setPixmap(QPixmap());
            ui->gifslot5->setMovie(skull);
            skull->start();
        }

    } else if (totaldamage2 < 0) {
        playerHealth = playerHealth + totaldamage2;
        ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");
        ui->healthplayer->setValue(playerHealth);
        if (attacker2 == true) {
            // Assuming attacker1Fighter is a string
            std::string modifiedString = attacker2Fighter;

            // Remove "level2" if it exists in the string
            size_t pos = modifiedString.find("level2");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level2"
            }

            // Remove "level3" if it exists in the string
            pos = modifiedString.find("level3");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level3"
            }

            if(revertgoshi2 == true) {
                modifiedString = "goshi";
                revertgoshi2 = false;
            }

            // Push the modified string back into the cardStack
            cardStack.push_back(modifiedString);

            attacker2Fighter = "";
            attacker2 = false;
            ui->damagerange2->clear();
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);
            ui->attacker2card->setPixmap(QPixmap());
            ui->gifslot2->setMovie(skull);
            skull->start();
        }
    }
}

void MainWindow::endTurnBetter3()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    //assigning damage for player card in slot 2

    ui->gifslot3->raise();
    ui->gifslot3->raise();
    ui->gifslot3->raise();
    ui->gifslot3->raise();
    ui->gifslot6->raise();
    ui->gifslot6->raise();
    ui->gifslot6->raise();
    ui->gifslot6->raise();

    QTimer::singleShot(1000, this, [this]() {
        ui->gifslot3->lower();
        ui->gifslot3->lower();
        ui->gifslot3->lower();
        ui->gifslot3->lower();
        ui->gifslot6->lower();
        ui->gifslot6->lower();
        ui->gifslot6->lower();
        ui->gifslot6->lower();
        ui->gifslot3->setMovie(nullptr);
        ui->gifslot6->setMovie(nullptr);

    });

    if (attacker3 == true) {
        if (attacker3Fighter == "kenshi" || attacker3Fighter == "ronin" || attacker3Fighter == "kyudo") {
            damageGenerated3 = rand() % 6 + 1;
        } else if (attacker3Fighter == "kenshilevel2" || attacker3Fighter == "kyudolevel2" || attacker3Fighter == "roninlevel2") {
            damageGenerated3 = rand() % 7 + 2;
        } else if (attacker3Fighter == "kenshilevel3" || attacker3Fighter == "kyudolevel3" || attacker3Fighter == "roninlevel3") {
            damageGenerated3 = rand() % 8 + 3;
        } else if (attacker3Fighter == "samurai") {
            damageGenerated3 = rand() % 10 + 1;
        } else if (attacker3Fighter == "goshi") {
            damageGenerated3 = rand() % 3 + 1;
        } else if (attacker3Fighter == "hatamoto") {
            damageGenerated3 = rand() % 15 + 1;
        } else if (attacker3Fighter == "shogun") {
            damageGenerated3 = rand() % 10 + 1;
        } else if (attacker3Fighter == "sumo") {
            damageGenerated3 = rand() % 20 + 1;
        }

    } else {
        damageGenerated3 = 0;
    }

    //assigning damage for opponent card in slot 4
    if (attacker6 == true) {
        if (attacker6Fighter == "kenshi" || attacker6Fighter == "ronin" || attacker6Fighter == "kyudo") {
            damageGenerated6 = rand() % 6 + 1;
        } else if (attacker6Fighter == "kenshilevel2" || attacker6Fighter == "kyudolevel2" || attacker6Fighter == "roninlevel2") {
            damageGenerated6 = rand() % 7 + 2;
        } else if (attacker6Fighter == "kenshilevel3" || attacker6Fighter == "kyudolevel3" || attacker6Fighter == "roninlevel3") {
            damageGenerated6 = rand() % 8 + 3;
        } else if (attacker6Fighter == "samurai") {
            damageGenerated6 = rand() % 10 + 1;
        } else if (attacker6Fighter == "goshi") {
            damageGenerated6 = rand() % 3 + 1;
        } else if (attacker6Fighter == "hatamoto") {
            damageGenerated6 = rand() % 15 + 1;
        } else if (attacker6Fighter == "shogun") {
            damageGenerated6 = rand() % 10 + 1;
        }

    } else {
        damageGenerated6 = 0;
    }

    //kenshi weakness player
    if ((attacker3Fighter == "kenshi" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "kenshilevel3")
    && (attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated6;
        damageGenerated6 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated6;
        ui->double6->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness player
    } else if ((attacker3Fighter == "ronin" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "roninlevel3")
    && (attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2" || attacker6Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated6;
        damageGenerated6 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated6;
        ui->double6->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness player
    } else if ((attacker3Fighter == "kyudo" || attacker3Fighter == "kyudolevel2" || attacker3Fighter == "kyudolevel3")
    && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated6;
        damageGenerated6 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated6;
        ui->double6->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker3 == true && attacker3Fighter != "shogun")
    && (attacker6Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated6;
        damageGenerated6 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated6;
        ui->double6->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }

    //kenshi weakness opponent
    else if ((attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "kenshilevel3")
        && (attacker3Fighter == "ronin" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "roninlevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated3;
        damageGenerated3 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated3;
        ui->double3->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //ronin weakness opponent
    } else if ((attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "roninlevel3")
        && (attacker3Fighter == "kyudo" || attacker3Fighter == "kyudolevel2" || attacker3Fighter == "kyudolevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated3;
        damageGenerated3 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated3;
        ui->double3->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    //kyudo weakness opponent
    } else if ((attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2" || attacker6Fighter == "kyudolevel3")
        && (attacker3Fighter == "kenshi" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "kenshilevel3")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated3;
        damageGenerated3 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated3;
        ui->double3->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    } else if ((attacker6 == true && attacker6Fighter != "shogun")
        && (attacker3Fighter == "shogun")) {
        qDebug() << "DAMAGE DOUBLED! DAMAGE BEFORE:" << damageGenerated3;
        damageGenerated3 *= 2;
        qDebug() << "DAMAGE NOW:" << damageGenerated3;
        ui->double3->setText("<html><head/><body><p align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:25pt; color:#bc002d;\"><b>X2</b></span></p></body></html>");
    }


    if (iswager == true) {
        qDebug() << "WAGER DAMAGE DOUBLED";
        damageGenerated3*=2;
        damageGenerated6*=2;
    }

    //team2 attack bonus
    if (team2 == true && attacker3 == true) {
        damageGenerated3++;
    }

    //evaluating damage
    int totaldamage3 = damageGenerated3 - damageGenerated6;

    //updating damage labels
    ui->damage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated3) + "</span></div>");
    ui->damage6->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(damageGenerated6) + "</span></div>");
    ui->totalDamage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(totaldamage3) + "</span></div>");


    //assigning health damage to player and updating labels
    if (totaldamage3 > 0) {
        opponentHealth = opponentHealth - totaldamage3;
        ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
        ui->healthopp->setValue(opponentHealth);
        if(attacker6 == true) {
            attacker6Fighter = "";
            attacker6 = false;
            ui->damagerange6->clear();
            ui->attacker6card->setPixmap(QPixmap());
            ui->gifslot6->setMovie(skull);
            skull->start();
        }

    } else if (totaldamage3 < 0) {
        playerHealth = playerHealth + totaldamage3;
        ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");
        ui->healthplayer->setValue(playerHealth);
        if (attacker3 == true) {
            // Assuming attacker1Fighter is a string
            std::string modifiedString = attacker3Fighter;

            // Remove "level2" if it exists in the string
            size_t pos = modifiedString.find("level2");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level2"
            }

            // Remove "level3" if it exists in the string
            pos = modifiedString.find("level3");
            if (pos != std::string::npos) {
                modifiedString.erase(pos, 6); // 6 is the length of "level3"
            }

            if(revertgoshi3 == true) {
                modifiedString = "goshi";
                revertgoshi3 = false;
            }

            // Push the modified string back into the cardStack
            cardStack.push_back(modifiedString);

            attacker3Fighter = "";
            attacker3 = false;
            ui->damagerange3->clear();
            QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
            ui->decknumbercount->setText(text);
            ui->attacker3card->setPixmap(QPixmap());
            ui->gifslot3->setMovie(skull);
            skull->start();
        }
    }
    checkHealth();



}

void MainWindow::on_roninbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Lightweight and experienced swordsman-<br>(lvl1: 1-6) (level2: 1-8) (level3: 1-10)</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: Kenshi</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: Kyudo</span></p></body></html>");

}

void MainWindow::on_kenshibutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Heavily armored and skilled swordsman-<br>(lvl1: 1-6) (level2: 1-8) (level3: 1-10)</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: Kyudo</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: Ronin</span></p></body></html>");
}

void MainWindow::on_kyudobutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Agile and sharp bowman-<br>(lvl1: 1-6) (level2: 1-8) (level3: 1-10)</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: Ronin</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: Kenshi</span></p></body></html>");

}

void MainWindow::on_samuraibutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Highly skilled and disciplined warrior-<br> Deals 1 - 10 Damage</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: None</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: None</span></p></body></html>");
}

void MainWindow::on_diminishbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Devolve opponent's cards (kyudo, ronin, kenshi)-</span></p></body></html>");
}

void MainWindow::on_upgradebutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Upgrade one of your cards (kyudo, ronin, kenshi)-</span></p></body></html>");

}

void MainWindow::on_wagerbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-All damage for the turn the card is played is doubled!-</span></p></body></html>");

}

void MainWindow::on_expellbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Remove an opponents card from the battlefield-</span></p></body></html>");

}

void MainWindow::on_blessingbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Gain three mana-</span></p></body></html>");

}

void MainWindow::on_fortifybutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Upgrade all of your eligible cards (kyudo, ronin, kenshi)-</span></p></body></html>");

}

void MainWindow::on_strikebutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Deals 10 damage directly to the opponent-</span></p></body></html>");

}

void MainWindow::on_goshibutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Warrior in training! Becomes Samurai the turn after-<br> Deals 1 - 3 Damage</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: None</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: None</span></p></body></html>");

}

void MainWindow::on_hatamotobutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Warrior General-<br> Deals 1 - 15 Damage</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: None</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: None</span></p></body></html>");
}

void MainWindow::on_shogunbutton_clicked()
{
    ui->cardinfo->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">-Supreme Military Commander-<br> Deals 1 - 10 Damage</span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Strong Against: ALL </span><br><span style=\" font-family:'Darumadrop One'; font-size:16pt; color:#bc002d;\">Weak Against: None</span></p></body></html>");

}

void MainWindow::on_removecard_clicked()
{
    if (ui->QlistWidgetDeck->currentItem()) {
        const QString& s = ui->QlistWidgetDeck->currentItem()->text();
        qDebug() << "Selected item text:" << s;

        string itemToRemove = s.toStdString();

        if(playerCards.size() > 7) {
            auto it = std::find(playerCards.begin(), playerCards.end(), itemToRemove);
            if (it != playerCards.end()) {
                playerCards.erase(it);
                delete ui->QlistWidgetDeck->takeItem(ui->QlistWidgetDeck->currentRow());
                ui->decktitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Deck " + QString::number(playerCards.size()) + "/20</span></div>");
                cardStorage.push_back(itemToRemove);
                QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/" + QString::fromStdString(itemToRemove) + "f.png"), QString::fromStdString(itemToRemove), ui->QlistWidgetStorage);
                ui->QlistWidgetStorage->addItem(item);
                item->setForeground(QColor(188, 0, 45));
            }
        } else {
            qDebug() << "No item selected.";
        }
    } else {
        qDebug() << "No item selected.";
    }
}

void MainWindow::on_addbutton_clicked()
{

    QListWidgetItem *selectedItem = ui->QlistWidgetStorage->currentItem();
    if (selectedItem) {
        QString selectedItemText = selectedItem->text();
        std::string itemToRemove = selectedItemText.toStdString();
        auto it = std::find(cardStorage.begin(), cardStorage.end(), itemToRemove);
        if (it != cardStorage.end()) {
            cardStorage.erase(it);
            playerCards.push_back(itemToRemove);
            delete ui->QlistWidgetStorage->takeItem(ui->QlistWidgetStorage->currentRow());
            ui->decktitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Deck " + QString::number(playerCards.size()) + "/20</span></div>");
            QListWidgetItem *item = new QListWidgetItem(QIcon(":/images/" + QString::fromStdString(itemToRemove) + "f.png"), QString::fromStdString(itemToRemove), ui->QlistWidgetDeck);
            ui->QlistWidgetDeck->addItem(item);
            item->setForeground(QColor(188, 0, 45));
        }
    } else {
        qDebug() << "No item selected.";
    }

}


void MainWindow::on_return1_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->QlistWidgetDeck->clear();
    ui->QlistWidgetStorage->clear();


}

void MainWindow::opponent1()
{


    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 5;
    int upgradeEnergy = 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 3 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if(randomIndex == 1) {
            chosen = "kenshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3) {
            chosen = "ronin";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));
}

void MainWindow::opponent2()
{


    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 5;
    int upgradeEnergy = 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                     ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                     ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                     ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 4 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if(randomIndex == 1) {
            chosen = "kenshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3) {
            chosen = "ronin";
        } else if (randomIndex == 4) {
            chosen = "samurai";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));
}

void MainWindow::opponent3()
{


    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 5;
    int upgradeEnergy = 2;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");

                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");

                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");

                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");

                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 6 || randomIndex == 7) {
            chosen = "kenshi";
        } else if (randomIndex == 1 || randomIndex == 2 || randomIndex == 3 || randomIndex == 4 || randomIndex == 5) {
            chosen = "kyudo";
        } else if (randomIndex == 8 || randomIndex == 9) {
            chosen = "ronin";
        } else if (randomIndex == 10) {
            chosen = "samurai";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));
}

void MainWindow::opponent4()
{

    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 5;
    int upgradeEnergy = 2;

    int randomIndexSpell = rand() % 10 + 1;

    if (randomIndexSpell == 1 && (attacker1 == true || attacker2 == true || attacker3 == true)) {
        bool manifold = true;
        while (manifold == true) {
            int randomIndexTarget = rand() % 3 + 1;
            if (randomIndexTarget == 1 && attacker1 == true) {
                string modifiedString = attacker1Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);

                attacker1Fighter = "";
                attacker1 = false;
                ui->attacker1card->setPixmap(QPixmap());
                ui->gifslot1->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 2;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the left lane<br>ニューカードインレフトレーン! 💀</span></p></body></html>");
                ui->damagerange1->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 2 && attacker2 == true) {
                string modifiedString = attacker2Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker2Fighter = "";
                attacker2 = false;
                ui->attacker2card->setPixmap(QPixmap());
                ui->gifslot2->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 2;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the middle lane<br>ニューカードインミドルレーン! 💀</span></p></body></html>");
                ui->damagerange2->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 3 && attacker3 == true) {
                string modifiedString = attacker3Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker3Fighter = "";
                attacker3 = false;
                ui->attacker3card->setPixmap(QPixmap());
                ui->gifslot3->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 2;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the right lane<br>ニューカードインライトレーン! 💀</span></p></body></html>");
                ui->damagerange3->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->setMovie(nullptr);
                });
            }

        }

    }



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1) {
            chosen = "kenshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3 || randomIndex == 4) {
            chosen = "ronin";
        } else if (randomIndex == 5 || randomIndex == 6 || randomIndex == 7 || randomIndex == 8) {
            chosen = "samurai";
        } else if (randomIndex == 9 || randomIndex == 10) {
            chosen = "goshi";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker4card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker5card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker6card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));
}

void MainWindow::opponent5()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 6;
    int upgradeEnergy = 3;

    int randomIndexSpell = rand() % 10 + 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 3 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1) {
            chosen = "kenshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3) {
            chosen = "ronin";
        }


        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}

void MainWindow::opponent6()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 6;
    int upgradeEnergy = 1;

    int randomIndexSpell = rand() % 10 + 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker1 == true && (attacker1Fighter == "kenshilevel3" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "roninlevel3" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "kyudolevel3" || attacker1Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                upgrade->start();
                if (attacker1Fighter == "kenshilevel3") {
                    attacker1Fighter = "kenshilevel2";
                    ui->attacker1card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker1Fighter == "kenshilevel2") {
                    attacker1Fighter = "kenshi";
                    ui->attacker1card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker1Fighter == "roninlevel3") {
                    attacker1Fighter = "roninlevel2";
                    ui->attacker1card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker1Fighter == "roninlevel2") {
                    attacker1Fighter = "ronin";
                    ui->attacker1card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker1Fighter == "kyudolevel3") {
                    attacker1Fighter = "kyudolevel2";
                    ui->attacker1card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudo";
                    ui->attacker4card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
        else if (randomIndex == 2) {
            if (attacker2 == true && (attacker2Fighter == "kenshilevel3" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "roninlevel3" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "kyudolevel3" || attacker2Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                if (attacker2Fighter == "kenshilevel3") {
                    attacker2Fighter = "kenshilevel2";
                    ui->attacker2card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "kenshilevel2") {
                    attacker2Fighter = "kenshi";
                    ui->attacker2card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker2Fighter == "roninlevel3") {
                    attacker2Fighter = "roninlevel2";
                    ui->attacker2card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "roninlevel2") {
                    attacker2Fighter = "ronin";
                    ui->attacker2card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker2Fighter == "kyudolevel3") {
                    attacker2Fighter = "kyudolevel2";
                    ui->attacker2card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "kyudolevel2") {
                    attacker2Fighter = "kyudo";
                    ui->attacker2card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
        else if (randomIndex == 3) {
            if (attacker3 == true && (attacker3Fighter == "kenshilevel3" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "roninlevel3" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "kyudolevel3" || attacker3Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                if (attacker3Fighter == "kenshilevel3") {
                    attacker3Fighter = "kenshilevel2";
                    ui->attacker3card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "kenshilevel2") {
                    attacker3Fighter = "kenshi";
                    ui->attacker3card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\"Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker3Fighter == "roninlevel3") {
                    attacker3Fighter = "roninlevel2";
                    ui->attacker3card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "roninlevel2") {
                    attacker3Fighter = "ronin";
                    ui->attacker3card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker3Fighter == "kyudolevel3") {
                    attacker3Fighter = "kyudolevel2";
                    ui->attacker3card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "kyudolevel2") {
                    attacker3Fighter = "kyudo";
                    ui->attacker3card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker1 == true && (attacker1Fighter == "kenshilevel3" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "roninlevel3" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "kyudolevel3" || attacker1Fighter == "kyudolevel2")) ||
             (attacker2 == true && (attacker2Fighter == "kenshilevel3" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "roninlevel3" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "kyudolevel3" || attacker2Fighter == "kyudolevel2")) ||
             (attacker3 == true && (attacker3Fighter == "kenshilevel3" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "roninlevel3" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "kyudolevel3" || attacker3Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1) {
            chosen = "goshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3) {
            chosen = "ronin";
        }


        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker4card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker5card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "goshi") {
                energy--;
                ui->attacker6card->setPixmap(goshi);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Goshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-3</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}

void MainWindow::opponent7()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 6;
    int upgradeEnergy = 1;

    int randomIndexSpell = rand() % 10 + 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1 || randomIndex == 2) {
            chosen = "kenshi";
        } else if (randomIndex == 3 || randomIndex == 4) {
            chosen = "kyudo";
        } else if (randomIndex == 5 || randomIndex == 6) {
            chosen = "ronin";
        } else if (randomIndex == 7 || randomIndex == 8) {
            chosen = "samurai";
        } else if (randomIndex == 9 || randomIndex == 10) {
            chosen = "hatamoto";


        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker4card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }


            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker5card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }


            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker6card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }
        }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}

void MainWindow::opponent8()
{

    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 7;
    int upgradeEnergy = 3;

    int randomIndexSpell = rand() % 10 + 1;

    if (randomIndexSpell == 1 || randomIndexSpell == 2 || randomIndexSpell == 3 && (attacker1 == true || attacker2 == true || attacker3 == true)) {
        bool manifold = true;
        while (manifold == true) {
            int randomIndexTarget = rand() % 3 + 1;
            if (randomIndexTarget == 1 && attacker1 == true) {
                string modifiedString = attacker1Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);

                attacker1Fighter = "";
                attacker1 = false;
                ui->attacker1card->setPixmap(QPixmap());
                ui->gifslot1->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the left lane<br>ニューカードインレフトレーン! 💀</span></p></body></html>");
                ui->damagerange1->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 2 && attacker2 == true) {
                string modifiedString = attacker2Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker2Fighter = "";
                attacker2 = false;
                ui->attacker2card->setPixmap(QPixmap());
                ui->gifslot2->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the middle lane<br>ニューカードインミドルレーン! 💀</span></p></body></html>");
                ui->damagerange2->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 3 && attacker3 == true) {
                string modifiedString = attacker3Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker3Fighter = "";
                attacker3 = false;
                ui->attacker3card->setPixmap(QPixmap());
                ui->gifslot3->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the right lane<br>ニューカードインライトレーン! 💀</span></p></body></html>");
                ui->damagerange3->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->setMovie(nullptr);
                });
            }

        }

    }



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>"); \
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                    ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1 || randomIndex == 2) {
            chosen = "kenshi";
        } else if (randomIndex == 3 || randomIndex == 4) {
            chosen = "kyudo";
        } else if (randomIndex == 5 || randomIndex == 6) {
            chosen = "ronin";
        } else if (randomIndex == 7 || randomIndex == 8) {
            chosen = "samurai";
        } else if (randomIndex == 9 || randomIndex == 10) {
            chosen = "shogun";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker4card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker5card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy-shogunCost;
                ui->attacker6card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}

void MainWindow::opponent9()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 6;
    int upgradeEnergy = 3;

    int randomIndexSpell = rand() % 10 + 1;



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker1 == true && (attacker1Fighter == "kenshilevel3" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "roninlevel3" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "kyudolevel3" || attacker1Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                upgrade->start();
                if (attacker1Fighter == "kenshilevel3") {
                    attacker1Fighter = "kenshilevel2";
                    ui->attacker1card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker1Fighter == "kenshilevel2") {
                    attacker1Fighter = "kenshi";
                    ui->attacker1card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker1Fighter == "roninlevel3") {
                    attacker1Fighter = "roninlevel2";
                    ui->attacker1card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker1Fighter == "roninlevel2") {
                    attacker1Fighter = "ronin";
                    ui->attacker1card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker1Fighter == "kyudolevel3") {
                    attacker1Fighter = "kyudolevel2";
                    ui->attacker1card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudo";
                    ui->attacker4card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
        else if (randomIndex == 2) {
            if (attacker2 == true && (attacker2Fighter == "kenshilevel3" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "roninlevel3" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "kyudolevel3" || attacker2Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                if (attacker2Fighter == "kenshilevel3") {
                    attacker2Fighter = "kenshilevel2";
                    ui->attacker2card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "kenshilevel2") {
                    attacker2Fighter = "kenshi";
                    ui->attacker2card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker2Fighter == "roninlevel3") {
                    attacker2Fighter = "roninlevel2";
                    ui->attacker2card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "roninlevel2") {
                    attacker2Fighter = "ronin";
                    ui->attacker2card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker2Fighter == "kyudolevel3") {
                    attacker2Fighter = "kyudolevel2";
                    ui->attacker2card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker2Fighter == "kyudolevel2") {
                    attacker2Fighter = "kyudo";
                    ui->attacker2card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
        else if (randomIndex == 3) {
            if (attacker3 == true && (attacker3Fighter == "kenshilevel3" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "roninlevel3" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "kyudolevel3" || attacker3Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                if (attacker3Fighter == "kenshilevel3") {
                    attacker3Fighter = "kenshilevel2";
                    ui->attacker3card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kenshi has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "kenshilevel2") {
                    attacker3Fighter = "kenshi";
                    ui->attacker3card->setPixmap(kenshilevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\"Your Kenshi has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker3Fighter == "roninlevel3") {
                    attacker3Fighter = "roninlevel2";
                    ui->attacker3card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "roninlevel2") {
                    attacker3Fighter = "ronin";
                    ui->attacker3card->setPixmap(roninlevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Ronin has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
                else if (attacker3Fighter == "kyudolevel3") {
                    attacker3Fighter = "kyudolevel2";
                    ui->attacker3card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 2! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
                }
                else if (attacker3Fighter == "kyudolevel2") {
                    attacker3Fighter = "kyudo";
                    ui->attacker3card->setPixmap(kyudolevel1);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your Kyudo has been downgraded to level 1! ☹️</span></p></body></html>");
                    ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
                }
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker1 == true && (attacker1Fighter == "kenshilevel3" || attacker1Fighter == "kenshilevel2" || attacker1Fighter == "roninlevel3" || attacker1Fighter == "roninlevel2" || attacker1Fighter == "kyudolevel3" || attacker1Fighter == "kyudolevel2")) ||
             (attacker2 == true && (attacker2Fighter == "kenshilevel3" || attacker2Fighter == "kenshilevel2" || attacker2Fighter == "roninlevel3" || attacker2Fighter == "roninlevel2" || attacker2Fighter == "kyudolevel3" || attacker2Fighter == "kyudolevel2")) ||
             (attacker3 == true && (attacker3Fighter == "kenshilevel3" || attacker3Fighter == "kenshilevel2" || attacker3Fighter == "roninlevel3" || attacker3Fighter == "roninlevel2" || attacker3Fighter == "kyudolevel3" || attacker3Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1) {
            chosen = "kenshi";
        } else if (randomIndex == 2) {
            chosen = "kyudo";
        } else if (randomIndex == 3) {
            chosen = "ronin";
        } else if (randomIndex == 4) {
            chosen = "samurai";
        } else if (randomIndex == 5) {
            chosen = "hatamoto";
        } else if (randomIndex == 6 || randomIndex == 7 || randomIndex == 8 || randomIndex == 9 || randomIndex == 10) {
            chosen = "shogun";



        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker4card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker4card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker5card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker5card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }


            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-6</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker6card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker6card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}

void MainWindow::opponent10()
{
    QMovie *skull = new QMovie(":/images/skull.gif");
    QMovie *upgrade = new QMovie(":/images/spawn.gif");
    QMovie *newthing = new QMovie(":/images/newthing.gif");
    srand(time(nullptr));  //man i got no damn clue what this is!
    int energy = 8;
    int upgradeEnergy = 3;

    int randomIndexSpell = 3;

    if (randomIndexSpell == 1 || randomIndexSpell == 2 || randomIndexSpell == 3 && (attacker1 == true || attacker2 == true || attacker3 == true)) {
        bool manifold = true;
        while (manifold == true) {
            int randomIndexTarget = rand() % 3 + 1;
            if (randomIndexTarget == 1 && attacker1 == true) {
                string modifiedString = attacker1Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);

                attacker1Fighter = "";
                attacker1 = false;
                ui->attacker1card->setPixmap(QPixmap());
                ui->gifslot1->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the left lane<br>ニューカードインレフトレーン! 💀</span></p></body></html>");
                ui->damagerange1->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->lower();
                    ui->gifslot1->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 2 && attacker2 == true) {
                string modifiedString = attacker2Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker2Fighter = "";
                attacker2 = false;
                ui->attacker2card->setPixmap(QPixmap());
                ui->gifslot2->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the middle lane<br>ニューカードインミドルレーン! 💀</span></p></body></html>");
                ui->damagerange2->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->lower();
                    ui->gifslot2->setMovie(nullptr);
                });

            } else if (randomIndexTarget == 3 && attacker3 == true) {
                string modifiedString = attacker3Fighter;
                // Remove "level2" if it exists in the string
                size_t pos = modifiedString.find("level2");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level2"
                }
                // Remove "level3" if it exists in the string
                pos = modifiedString.find("level3");
                if (pos != std::string::npos) {
                    modifiedString.erase(pos, 6); // 6 is the length of "level3"
                }
                // Push the modified string back into the cardStack
                cardStack.push_back(modifiedString);
                attacker3Fighter = "";
                attacker3 = false;
                ui->attacker3card->setPixmap(QPixmap());
                ui->gifslot3->setMovie(skull);
                skull->start();
                manifold = false;
                upgradeEnergy = upgradeEnergy - 3;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Your card has been expelled in the right lane<br>ニューカードインライトレーン! 💀</span></p></body></html>");
                ui->damagerange3->clear();
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->lower();
                    ui->gifslot3->setMovie(nullptr);
                });
            }

        }

    }



    string chosen;

    do {
        int randomIndex = rand() % 3 + 1;

        if (randomIndex == 1) {
            if (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->raise();
                ui->gifslot4->setMovie(upgrade);
                upgrade->start();
                if (attacker4Fighter == "kenshi") {
                    attacker4Fighter = "kenshilevel2";
                    ui->attacker4card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker4Fighter == "kenshilevel2") {
                    attacker4Fighter = "kenshilevel3";
                    ui->attacker4card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker4Fighter == "ronin") {
                    attacker4Fighter = "roninlevel2";
                    ui->attacker4card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker4Fighter == "roninlevel2") {
                    attacker4Fighter = "roninlevel3";
                    ui->attacker4card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudo") {
                    attacker4Fighter = "kyudolevel2";
                    ui->attacker4card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker4Fighter == "kyudolevel2") {
                    attacker4Fighter = "kyudolevel3";
                    ui->attacker4card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->lower();
                    ui->gifslot4->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 2) {
            if (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->raise();
                ui->gifslot5->setMovie(upgrade);
                upgrade->start();
                if (attacker5Fighter == "kenshi") {
                    attacker5Fighter = "kenshilevel2";
                    ui->attacker5card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker5Fighter == "kenshilevel2") {
                    attacker5Fighter = "kenshilevel3";
                    ui->attacker5card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker5Fighter == "ronin") {
                    attacker5Fighter = "roninlevel2";
                    ui->attacker5card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker5Fighter == "roninlevel2") {
                    attacker5Fighter = "roninlevel3";
                    ui->attacker5card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudo") {
                    attacker5Fighter = "kyudolevel2";
                    ui->attacker5card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker5Fighter == "kyudolevel2") {
                    attacker5Fighter = "kyudolevel3";
                    ui->attacker5card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }

                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->lower();
                    ui->gifslot5->setMovie(nullptr);
                });
            }
        }
        else if (randomIndex == 3) {
            if (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2")) {
                upgradeEnergy--;
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->raise();
                ui->gifslot6->setMovie(upgrade);
                upgrade->start();
                if (attacker6Fighter == "kenshi") {
                    attacker6Fighter = "kenshilevel2";
                    ui->attacker6card->setPixmap(kenshilevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker6Fighter == "kenshilevel2") {
                    attacker6Fighter = "kenshilevel3";
                    ui->attacker6card->setPixmap(kenshilevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker6Fighter == "ronin") {
                    attacker6Fighter = "roninlevel2";
                    ui->attacker6card->setPixmap(roninlevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker6Fighter == "roninlevel2") {
                    attacker6Fighter = "roninlevel3";
                    ui->attacker6card->setPixmap(roninlevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudo") {
                    attacker6Fighter = "kyudolevel2";
                    ui->attacker6card->setPixmap(kyudolevel2);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 2<br>カード　アップグレード　トゥ　レベル　ツー</span></p></body></html>");
                }
                else if (attacker6Fighter == "kyudolevel2") {
                    attacker6Fighter = "kyudolevel3";
                    ui->attacker6card->setPixmap(kyudolevel3);
                    ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo has been upgraded to level 3<br>カード アップグレード トゥ レベル スリー</span></p></body></html>");
                }
                QTimer::singleShot(2500, this, [this]() {
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->lower();
                    ui->gifslot6->setMovie(nullptr);

                });
            }
        }
    } while (upgradeEnergy > 1 && (
             (attacker4 == true && (attacker4Fighter == "kenshi" || attacker4Fighter == "kenshilevel2" || attacker4Fighter == "ronin" || attacker4Fighter == "roninlevel2" || attacker4Fighter == "kyudo" || attacker4Fighter == "kyudolevel2")) ||
             (attacker5 == true && (attacker5Fighter == "kenshi" || attacker5Fighter == "kenshilevel2" || attacker5Fighter == "ronin" || attacker5Fighter == "roninlevel2" || attacker5Fighter == "kyudo" || attacker5Fighter == "kyudolevel2")) ||
             (attacker6 == true && (attacker6Fighter == "kenshi" || attacker6Fighter == "kenshilevel2" || attacker6Fighter == "ronin" || attacker6Fighter == "roninlevel2" || attacker6Fighter == "kyudo" || attacker6Fighter == "kyudolevel2"))
           ));





    do {
        int randomIndex = rand() % 10 + 1;
        int randomIndex2 = rand() % 3 + 1;

        if (randomIndex == 1 || randomIndex == 2 || randomIndex == 3) {
            chosen = "samurai";
        } else if (randomIndex == 4 || randomIndex == 5 || randomIndex == 6) {
            chosen = "hatamoto";
        } else if (randomIndex == 7 || randomIndex == 8 || randomIndex == 9 || randomIndex == 10) {
            chosen = "shogun";
        }

        if (randomIndex2 == 1 && attacker4 == false) {
            attacker4 = true;
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->raise();
            ui->gifslot4->setMovie(newthing);
            newthing->start();
            attacker4Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker4card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker4card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker4card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker4card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker4card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker4card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the left lane<br>ニューカードインレフトレーン</span></p></body></html>");
                ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->lower();
                ui->gifslot4->setMovie(nullptr);
            });

        } else if (randomIndex2 == 2 && attacker5 == false) {
            attacker5 = true;
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->raise();
            ui->gifslot5->setMovie(newthing);
            newthing->start();
            attacker5Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker5card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker5card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker5card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker5card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy - shogunCost;
                ui->attacker5card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker5card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the middle lane<br>ニューカードインミドルレーン</span></p></body></html>");
                ui->damagerange5->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->lower();
                ui->gifslot5->setMovie(nullptr);
            });

        } else if (randomIndex2 == 3 && attacker6 == false) {
            attacker6 = true;
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->raise();
            ui->gifslot6->setMovie(newthing);

            newthing->start();
            attacker6Fighter = chosen;
            if (chosen == "kenshi") {
                energy = energy - kenshiCost;
                ui->attacker6card->setPixmap(kenshilevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kenshi played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
            } else if (chosen == "kyudo") {
                ui->attacker6card->setPixmap(kyudolevel1);
                energy = energy - kyudoCost;
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Kyudo played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
            } else if (chosen == "ronin") {
                energy = energy - roninCost;
                ui->attacker6card->setPixmap(roninlevel1);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Ronin played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
            } else if (chosen == "samurai") {
                energy = energy - samuraiCost;
                ui->attacker6card->setPixmap(samurai);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Samurai played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "shogun") {
                energy = energy-shogunCost;
                ui->attacker6card->setPixmap(shogun);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Shogun played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
            } else if (chosen == "hatamoto") {
                energy = energy - hatamotoCost;
                ui->attacker6card->setPixmap(hatamoto);
                ui->console->append("<html><head/><body><p align=\"left\"><span style=\" font-family:'Darumadrop One'; font-size:10pt; color:#bc002d;\">Hatamoto played in the right lane<br>ニューカードインライトレーン</span></p></body></html>");
                ui->damagerange6->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-15</span></p></body></html>");
            }

            QTimer::singleShot(3800, this, [this]() {
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->lower();
                ui->gifslot6->setMovie(nullptr);
            });
        }


    } while ((energy > 1) && (attacker4 == false || attacker5 == false || attacker6 == false));

}




void MainWindow::on_next_clicked()
{

    if (level == 1) {
        opponent1();
        qDebug() << "opponent 1";
    } else if (level == 2) {
        opponent2();
        qDebug() << "opponent 2";
    } else if (level == 3) {
        opponent3();
        qDebug() << "opponent 3";
    } else if (level == 4) {
        opponent4();
        qDebug() << "opponent 4";
    } else if (level == 5) {
        opponent5();
        qDebug() << "opponent 5";
    } else if (level == 6) {
        opponent6();
        qDebug() << "oppoonent 6";
    } else if (level == 7) {
        opponent7();
        qDebug() << "opponent 7";
    } else if (level == 8) {
       opponent8();
       qDebug() << "opponent 8";
    } else if (level == 9) {
        opponent9();
        qDebug() << "opponent 9";
    } else if (level == 10) {
        opponent10();
        qDebug() << "opponent 10";
    }


    ui->damage1->clear();
    ui->damage2->clear();
    ui->damage3->clear();
    ui->damage4->clear();
    ui->damage5->clear();
    ui->damage6->clear();
    ui->totalDamage1->clear();
    ui->totalDamage2->clear();
    ui->totalDamage3->clear();
    ui->double1->clear();
    ui->double2->clear();
    ui->double3->clear();
    ui->double4->clear();
    ui->double5->clear();
    ui->double6->clear();

    giveCards();
    ui->next->setEnabled(false);
    ui->next->setVisible(false);

    QTimer::singleShot(3000, this, [this]() {
        ui->endturn->setEnabled(true);
        ui->endturn->setVisible(true);

    });

    //upgrade the goshi to samurai

    if (attacker1 == true && attacker1Fighter == "goshi") {
        attacker1Fighter = "samurai";
        ui->attacker1card->setPixmap(samurai);
        revertgoshi1 = true;
    } else if (attacker2 == true && attacker2Fighter == "goshi") {
        attacker2Fighter = "samurai";
        ui->attacker2card->setPixmap(samurai);
        revertgoshi2 = true;
    } else if (attacker3 == true && attacker3Fighter == "goshi") {
        attacker3Fighter = "samurai";
        ui->attacker3card->setPixmap(samurai);
        revertgoshi3 = true;
    }


}

void MainWindow::on_endturn_clicked()
{


    endTurnBetter1();



    if (attacker4 == true && attacker4Fighter == "goshi") {
    attacker4Fighter = "samurai";
    ui->attacker4card->setPixmap(samurai);
    ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
    }
    QTimer::singleShot(1000, this, [this]() {
        endTurnBetter2();
        if (attacker5 == true && attacker5Fighter == "goshi") {
            attacker5Fighter = "samurai";
            ui->attacker5card->setPixmap(samurai);
            ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");

        }
    });
    QTimer::singleShot(2000, this, [this]() {
        endTurnBetter3();
        if (attacker6 == true && attacker6Fighter == "goshi") {
            attacker6Fighter = "samurai";
            ui->attacker6card->setPixmap(samurai);
            ui->damagerange4->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">1-10</span></p></body></html>");
        }
    });

    QTimer::singleShot(3000, this, [this]() {
        iswager = false;
    });




    playerEnergy = 0;
    ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
    ui->endturn->setEnabled(false);
    ui->endturn->setVisible(false);
    QTimer::singleShot(3000, this, [this]() {
        ui->next->setEnabled(true);
        ui->next->setVisible(true);
    });







}


void MainWindow::on_begin_clicked()
{
   playerEnergy = 0;
   ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
   cardStack = playerCards;
   ui->stackedWidget->setCurrentIndex(3);
   giveCards();
   if (level == 1) {
       opponent1();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">SAITO さいとう</span></p></body></html>");
       ui->profile->setPixmap(enemypicture10);
   } else if (level == 2) {
       opponent2();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">NOBORU のぼる</span></p></body></html>");
       ui->profile->setPixmap(enemypicture9);
   } else if (level == 3) {
       opponent3();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">KASAHARA かさはら</span></p></body></html>");
       ui->profile->setPixmap(enemypicture8);
   } else if (level == 4) {
       opponent4();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">SUZUKI すずき</span></p></body></html>");
       ui->profile->setPixmap(enemypicture7);
   } else if (level == 5) {
       opponent5();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">DILABUN ディラブン</span></p></body></html>");
       ui->profile->setPixmap(enemypicture6);
   } else if (level == 6) {
       opponent6();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">TAKAHASHI たかはしぞ</span></p></body></html>");
       ui->profile->setPixmap(enemypicture5);
   } else if (level == 7) {
       opponent7();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">KAFUKU かふく</span></p></body></html>");
       ui->profile->setPixmap(enemypicture4);
   } else if (level == 8) {
      opponent8();
      ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
      ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">MISAKI みさき</span></p></body></html>");
      ui->profile->setPixmap(enemypicture3);
   } else if (level == 9) {
       opponent9();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">TORONAGA とらなが</span></p></body></html>");
       ui->profile->setPixmap(enemypicture2);
   } else if (level== 10) {
       opponent10();
       ui->levelgame->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">LEVEL " + QString::number(level) + "</span><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">/10</span></div>");
       ui->oppname->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">MUSASHI むさし</span></p></body></html>");
       ui->profile->setPixmap(enemypicture1);
   }
   ui->next->setEnabled(false);
   ui->next->setVisible(false);

   ui->endturn->setEnabled(true);
   ui->endturn->setVisible(true);
}

void MainWindow::checkHealth()
{
    if (playerHealth < 1) {
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        QMovie *rain = new QMovie(":/images/rain.gif");
        ui->movielabel->setMovie(rain);
        rain->start();

        QTimer::singleShot(5000, this, [this]() {

            QCoreApplication::quit();
        });


    } else if (opponentHealth < 1) {
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        ui->movielabel->raise();
        QMovie *confetti = new QMovie(":/images/giphy.gif");
        ui->movielabel->setMovie(confetti);
        confetti->start();

        QTimer::singleShot(3500, this, [this]() {
            level++;
            if (level == 11) {
                ui->stackedWidget->setCurrentIndex(7);
            }
            ui->progress->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:72pt; color:#bc002d;\">" + QString::number(level) + "</span>/10</div>");
            ui->healthplayertitle_2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:36pt; color:#bc002d;\">Health: " + QString::number(playerHealth) + "</span></div>");
            ui->healthplayer_2->setValue(playerHealth);
            ui->progress->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:72pt; color:#bc002d;\">" + QString::number(level) + "/10</span></p></body></html>");
            opponentHealth = 100;
            ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
            ui->healthopp->setValue(opponentHealth);
            ui->container1card->setPixmap(QPixmap());
            container1 = false;
            container2 = false;
            container3 = false;
            container4 = false;
            container5 = false;
            attacker1 = false;
            attacker2 = false;
            attacker3 = false;
            attacker4 = false;
            attacker5 = false;
            attacker6 = false;
            attacker1Fighter = "";
            attacker2Fighter = "";
            attacker3Fighter = "";
            attacker4Fighter = "";
            attacker5Fighter = "";
            attacker6Fighter = "";
            ui->attacker1card->setPixmap(QPixmap());
            ui->attacker2card->setPixmap(QPixmap());
            ui->attacker3card->setPixmap(QPixmap());
            ui->attacker4card->setPixmap(QPixmap());
            ui->attacker5card->setPixmap(QPixmap());
            ui->attacker6card->setPixmap(QPixmap());
            container1Card = "";
            ui->container2card->setPixmap(QPixmap());
            container2Card = "";
            ui->container3card->setPixmap(QPixmap());
            container3Card = "";
            ui->container4card->setPixmap(QPixmap());
            container4Card = "";
            ui->container5card->setPixmap(QPixmap());
            container5Card = "";
            ui->totalDamage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"></span></div>");
            ui->totalDamage2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"></span></div>");
            ui->totalDamage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage1->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage3->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage4->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage5->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->damage6->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\"</span></div>");
            ui->movielabel->lower();
            ui->movielabel->lower();
            ui->movielabel->lower();
            ui->movielabel->lower();
            ui->movielabel->lower();
            ui->movielabel->lower();



            ui->stackedWidget->setCurrentIndex(4);
            giveCardSelection();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->container1card_3->raise();
            ui->container1card_3->raise();
            ui->container1card_3->raise();
            ui->container1card_3->raise();
            ui->container1card_4->raise();
            ui->container1card_4->raise();
            ui->container1card_4->raise();
            ui->container1card_4->raise();
            ui->container1card_5->raise();
            ui->container1card_5->raise();
            ui->container1card_5->raise();
            ui->container1card_5->raise();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->container1card_2->raise();
            ui->pickthecardtitle->raise();
            ui->pickthecardtitle->raise();
            ui->pickthecardtitle->raise();
            cardsChosen = 0;
            healturns--;
            ui->progress_3->setText("<div align=\"center\"><span style=\"font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">Next heal in " + QString::number(healturns) + " turns</span></div>");
            giveHealth();
            ui->console->clear();
            ui->damagerange1->clear();
            ui->damagerange2->clear();
            ui->damagerange3->clear();
            ui->damagerange4->clear();
            ui->damagerange5->clear();
            ui->damagerange6->clear();
            ui->double1->clear();
            ui->double2->clear();
            ui->double3->clear();
            ui->double4->clear();
            ui->double5->clear();
            ui->double6->clear();






        });

    }

}


void MainWindow::on_yescardbutton_clicked()
{


    if(selectedCard == "strike") {
        cardStack.push_back("strike");
        QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
        ui->decknumbercount->setText(text);
        playerEnergy = playerEnergy - 3;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
        opponentHealth = opponentHealth - 10;
        ui->healthopptitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(opponentHealth) + "</span></div>");
        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">dealt 10 damage directly to opponent!</span></p></body></html>");
        ui->healthopp->setValue(opponentHealth);
        checkHealth();
    } else if (selectedCard == "wager") {
        cardStack.push_back("wager");
        QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
        ui->decknumbercount->setText(text);
        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">all damage this turn will be doubled!</span></p></body></html>");
        iswager = true;
    } else if (selectedCard == "blessing") {
        cardStack.push_back("blessing");
        QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
        ui->decknumbercount->setText(text);
        playerEnergy = playerEnergy + 2;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
    } else if (selectedCard == "fortify") {
        cardStack.push_back("fortify");
        QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
        ui->decknumbercount->setText(text);
        playerEnergy = playerEnergy - 3;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");

        //upgrading all the damn cards
        if (attacker1Fighter == "kenshi") {
            attacker1Fighter = "kenshilevel2";
            ui->attacker1card->setPixmap(kenshilevel2);
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker1Fighter == "kenshilevel2") {
            attacker1Fighter = "kenshilevel3";
            ui->attacker1card->setPixmap(kenshilevel3);
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker1Fighter == "ronin") {
            attacker1Fighter = "roninlevel2";
            ui->attacker1card->setPixmap(roninlevel2);
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker1Fighter == "roninlevel2") {
            attacker1Fighter = "roninlevel3";
            ui->attacker1card->setPixmap(roninlevel3);
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker1Fighter == "kyudo") {
            attacker1Fighter = "kyudolevel2";
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
            ui->attacker1card->setPixmap(kyudolevel2);
        } else if (attacker1Fighter == "kyudolevel2") {
            attacker1Fighter = "kyudolevel3";
            ui->attacker1card->setPixmap(kyudolevel3);
            ui->damagerange1->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        }

        if (attacker2Fighter == "kenshi") {
            attacker2Fighter = "kenshilevel2";
            ui->attacker2card->setPixmap(kenshilevel2);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker2Fighter == "kenshilevel2") {
            attacker2Fighter = "kenshilevel3";
            ui->attacker2card->setPixmap(kenshilevel3);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker2Fighter == "ronin") {
            attacker2Fighter = "roninlevel2";
            ui->attacker2card->setPixmap(roninlevel2);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker2Fighter == "roninlevel2") {
            attacker2Fighter = "roninlevel3";
            ui->attacker2card->setPixmap(roninlevel3);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker2Fighter == "kyudo") {
            attacker2Fighter = "kyudolevel2";
            ui->attacker2card->setPixmap(kyudolevel2);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker2Fighter == "kyudolevel2") {
            attacker2Fighter = "kyudolevel3";
            ui->attacker2card->setPixmap(kyudolevel3);
            ui->damagerange2->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        }

        if (attacker3Fighter == "kenshi") {
            attacker3Fighter = "kenshilevel2";
            ui->attacker3card->setPixmap(kenshilevel2);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker3Fighter == "kenshilevel2") {
            attacker3Fighter = "kenshilevel3";
            ui->attacker3card->setPixmap(kenshilevel3);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker3Fighter == "ronin") {
            attacker3Fighter = "roninlevel2";
            ui->attacker3card->setPixmap(roninlevel2);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker3Fighter == "roninlevel2") {
            attacker3Fighter = "roninlevel3";
            ui->attacker3card->setPixmap(roninlevel3);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        } else if (attacker3Fighter == "kyudo") {
            attacker3Fighter = "kyudolevel2";
            ui->attacker3card->setPixmap(kyudolevel2);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">2-8</span></p></body></html>");
        } else if (attacker3Fighter == "kyudolevel2") {
            attacker3Fighter = "kyudolevel3";
            ui->attacker3card->setPixmap(kyudolevel3);
            ui->damagerange3->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:18pt; color:#bc002d;\">3-10</span></p></body></html>");
        }




    } else if (selectedCard == "smith") {
        cardStack.push_back("smith");
        QString text = QString("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">%1</span></p></body></html>").arg(cardStack.size());
        ui->decknumbercount->setText(text);
        if(attacker1 == true) {
            playerEnergy++;
        }
        if(attacker2 == true) {
            playerEnergy++;
        }
        if(attacker3 == true) {
            playerEnergy++;
        }
        if(attacker4 == true) {
            playerEnergy++;
        }
        if(attacker5 == true) {
            playerEnergy++;
        }

        if(attacker6 == true) {
            playerEnergy++;
        }
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
    } else if (selectedCard == "restore") {
        playerHealth = playerHealth + 10;
        cardStack.push_back("restore");
        playerEnergy--;
        ui->energy->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerEnergy) + "</span></div>");
        if (team1 == false && playerHealth > 100) {
            playerHealth = 100;
        } else if (team1 == true && playerHealth > 125) {
            playerHealth = 125;
        }

        ui->healthplayertitle->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:28pt; color:#bc002d;\">" + QString::number(playerHealth) + "</span></div>");
        ui->healthplayer->setValue(playerHealth);
    }
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();

    if (alreadyClicked1 == true) {
        container1 = false;
        ui->container1card->move(originalPos1.x(), originalPos1.y());
        alreadyClicked1 = false;
        ui->container1card->setPixmap(QPixmap());
        container1Card = "";
    } else if (alreadyClicked2 == true) {
        container2 = false;
        ui->container2card->move(originalPos2.x(), originalPos2.y());
        alreadyClicked2 = false;
        ui->container2card->setPixmap(QPixmap());
        container2Card = "";
    } else if (alreadyClicked3 == true) {
        container3 = false;
        ui->container3card->move(originalPos3.x(), originalPos3.y());
        alreadyClicked3 = false;
        ui->container3card->setPixmap(QPixmap());
        container3Card = "";
    } else if (alreadyClicked4 == true) {
        container4 = false;
        ui->container4card->move(originalPos4.x(), originalPos4.y());
        ui->container4card->setPixmap(QPixmap());
        container4Card = "";
    } else if (alreadyClicked5 == true) {
        container5 = false;
        ui->container5card->move(originalPos5.x(), originalPos5.y());
        ui->container5card->setPixmap(QPixmap());
        container5Card = "";
    }

}


void MainWindow::on_nocardbutton_clicked()
{
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();
    ui->confirmframe->lower();

}

void MainWindow::giveCardSelection()
{
    int i = 0;

    // Array to store QPixmap variables
    QPixmap pixmaps[] = {roninlevel1, roninlevel1, roninlevel1, roninlevel1,
                         kenshilevel1, kenshilevel1, kenshilevel1, kenshilevel1,
                         kyudolevel1, kyudolevel1, kyudolevel1, kyudolevel1,
                         samurai, samurai, strike,
                         upgrade, upgrade, upgrade, upgrade, upgrade,
                         diminish, wager, expell, shogun, hatamoto, goshi, goshi,
                         fortify, blessing};

    // Corresponding values for each pixmap
    QString values[] = {"ronin", "ronin", "ronin", "ronin", // Two extra entries for ronin
                        "kenshi", "kenshi", "kenshi", "kenshi", // Two extra entries for kenshi
                        "kyudo", "kyudo", "kyudo", "kyudo",
                        "samurai", "samurai", "strike",
                        "upgrade", "upgrade", "upgrade", "upgrade", "upgrade",
                        "diminish", "wager", "expell", "shogun", "hatamoto", "goshi", "goshi", // Two extra entries for goshi
                        "fortify", "blessing"};


    // Array to store QLabel pointers
    QLabel* labels[] = {ui->container1card_2, ui->container1card_3, ui->container1card_4, ui->container1card_5, ui->container1card_6};

    // Create a QRandomGenerator object
    // Calculate the number of pixmaps
    int numPixmaps = sizeof(pixmaps) / sizeof(pixmaps[0]);
    // Generate a random index
    std::mt19937 rng(std::time(nullptr));

    // Assign random pixmaps to each QLabel and store the associated values
    for (i = 0; i < 5; i++) {
        // Generate a random index to choose a random pixmap
        std::uniform_int_distribution<int> distribution(0, numPixmaps - 1);
        int randomIndex = distribution(rng);

        // Set the pixmap for the current QLabel
        labels[i]->setPixmap(pixmaps[randomIndex]);

        // Store the associated value in the cardsArray
        cardsArray[i] = values[randomIndex];
        qDebug() << cardsArray[i];
    }


   cardsArray[0] = "";
   cardsArray[4] = "";
   ui->container1card_2->setPixmap(QPixmap());
   ui->container1card_6->setPixmap(QPixmap());
    ui->container1card_2->update();
    ui->container1card_3->update();
    ui->container1card_4->update();
    ui->container1card_5->update();
    ui->container1card_6->update();

}


void MainWindow::giveHealth() {
    if (healturns == 0) {
        if (team1 == true) {
            playerHealth = 125;
            ui->healthplayertitle_2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:36pt; color:#bc002d;\">Health: " + QString::number(playerHealth) + "</span></div>");
            ui->healthplayer_2->setValue(playerHealth);
            healturns = 3;
        } else {
            playerHealth = 100;
            ui->healthplayertitle_2->setText("<div align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:36pt; color:#bc002d;\">Health: " + QString::number(playerHealth) + "</span></div>");
            ui->healthplayer_2->setValue(playerHealth);
            healturns = 3;
        }
    }
}




void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {

        if (ui->container1card->geometry().contains(event->pos())) {
            if (alreadyClicked1 == false) {
                originalPos1 = ui->container1card->pos();
                ui->container1card->move(originalPos1.x(), originalPos1.y() - 15);
                alreadyClicked1 = true;


                //move the other cards back to position so not multiple are selected
                if(alreadyClicked2 == true) {
                ui->container2card->move(originalPos2.x(), originalPos2.y());
                alreadyClicked2 = false;
                }
                if(alreadyClicked3 == true) {
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                }
                if(alreadyClicked4 == true) {
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    alreadyClicked4 = false;
                }
                if(alreadyClicked5 == true) {
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    alreadyClicked5 = false;
                }


                qDebug() << container1Card;

                if (container1Card == "samurai") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "samurai";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                } else if (container1Card == "kenshi") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kenshi";
                } else if (container1Card == "kyudo") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kyudo";
                } else if (container1Card == "ronin") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "ronin";
                } else if (container1Card == "strike") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }


                    selectedCard = "strike";
                } else if (container1Card == "upgrade") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card to upgrade</span></p></body></html>");
                    selectedCard = "upgrade";
                } else if (container1Card == "expell") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card from the opponent to remove</span></p></body></html>");
                    selectedCard = "expell";
                } else if (container1Card == "wager") {
                    selectedCard = "wager";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                } else if (container1Card == "fortify") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "fortify";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container1Card == "blessing") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "blessing";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container1Card == "diminish") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">choose an active card from the opponent to downgrade</span></p></body></html>");
                    selectedCard = "diminish";
                } else if (container1Card == "hatamoto") {
                    if(playerEnergy <= 3) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "hatamoto";
                } else if (container1Card == "shogun") {
                    if(playerEnergy <= 4) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "shogun";
                } else if (container1Card == "goshi") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "goshi";
                } else if (container1Card == "smith") {
                        selectedCard = "smith";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                } else if (container1Card == "restore") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "restore";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }
                } else if (container1Card == "sumo") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                        selectedCard = "sumo";
                    }
                }

                }


        } else if (ui->container2card->geometry().contains(event->pos())) {
            if (alreadyClicked2 == false) {
                originalPos2 = ui->container2card->pos();
                ui->container2card->move(originalPos2.x(), originalPos2.y() - 15);
                alreadyClicked2 = true;

                //move the other cards back to position so not multiple are selected
                if(alreadyClicked1 == true) {
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                }
                if(alreadyClicked3 == true) {
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                }
                if(alreadyClicked4 == true) {
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    alreadyClicked4 = false;
                }
                if(alreadyClicked5 == true) {
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    alreadyClicked5 = false;
                }


                qDebug() << container2Card;

                if (container2Card == "samurai") {
                    if(playerEnergy < 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "samurai";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                } else if (container2Card == "kenshi") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kenshi";
                } else if (container2Card == "kyudo") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kyudo";
                } else if (container2Card == "ronin") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "ronin";
                } else if (container2Card == "strike") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "strike";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container2Card == "upgrade") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card to upgrade</span></p></body></html>");
                    selectedCard = "upgrade";
                } else if (container2Card == "expell") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card from the opponent to remove</span></p></body></html>");
                    selectedCard = "expell";
                } else if (container2Card == "wager") {
                    selectedCard = "wager";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();

                } else if (container2Card == "fortify") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "fortify";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container2Card == "blessing") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    {
                        selectedCard = "blessing";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container2Card == "diminish") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">choose an active card from the opponent to downgrade</span></p></body></html>");
                    selectedCard = "diminish";
                } else if (container2Card == "hatamoto") {
                    if(playerEnergy <= 3) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "hatamoto";
                } else if (container2Card == "shogun") {
                    if(playerEnergy <= 4) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "shogun";
                } else if (container2Card == "goshi") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "goshi";
                } else if (container2Card == "smith") {
                    selectedCard = "smith";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
            } else if (container2Card == "restore") {
                if(playerEnergy <= 0) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    selectedCard = "restore";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                }
            } else if (container2Card == "sumo") {
                if(playerEnergy <= 2) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "sumo";
                }
                }

            }

        } else if (ui->container3card->geometry().contains(event->pos())) {
            if (alreadyClicked3 == false) {
                originalPos3 = ui->container3card->pos();
                ui->container3card->move(originalPos3.x(), originalPos3.y() - 15);
                alreadyClicked3 = true;

                //move the other cards back to position so not multiple are selected
                if(alreadyClicked1 == true) {
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                }
                if(alreadyClicked2 == true) {
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                }
                if(alreadyClicked4 == true) {
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    alreadyClicked4 = false;
                }
                if(alreadyClicked5 == true) {
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    alreadyClicked5 = false;
                }

                qDebug() << container3Card;

                if (container3Card == "samurai") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "samurai";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                } else if (container3Card == "kenshi") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kenshi";
                } else if (container3Card == "kyudo") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kyudo";
                } else if (container3Card == "ronin") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "ronin";
                } else if (container3Card == "strike") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "strike";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container3Card == "upgrade") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card to upgrade</span></p></body></html>");
                    selectedCard = "upgrade";
                } else if (container3Card == "expell") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card from the opponent to remove</span></p></body></html>");
                    selectedCard = "expell";
                } else if (container3Card == "wager") {
                    selectedCard = "wager";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                } else if (container3Card == "fortify") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "fortify";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();

                    }

                } else if (container3Card == "blessing") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "blessing";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }

                } else if (container3Card == "diminish") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">choose an active card from the opponent to downgrade</span></p></body></html>");
                    selectedCard = "diminish";
                } else if (container3Card == "hatamoto") {
                    if(playerEnergy <= 3) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "hatamoto";
                } else if (container3Card == "shogun") {
                    if(playerEnergy <= 4) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "shogun";
                } else if (container3Card == "goshi") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "goshi";
                } else if (container3Card == "smith") {
                    selectedCard = "smith";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
            } else if (container3Card == "restore") {
                if(playerEnergy <= 0) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    selectedCard = "restore";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                }
            } else if (container3Card == "sumo") {
                if(playerEnergy <= 2) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "sumo";
                }
                }

            }

        } else if (ui->container4card->geometry().contains(event->pos())) {
            if (alreadyClicked4 == false) {
                originalPos4 = ui->container4card->pos();
                ui->container4card->move(originalPos4.x(), originalPos4.y() - 15);
                alreadyClicked4 = true;

                //move the other cards back to position so not multiple are selected
                if(alreadyClicked1 == true) {
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                }
                if(alreadyClicked2 == true) {
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                }
                if(alreadyClicked3 == true) {
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                }
                if(alreadyClicked5 == true) {
                    ui->container5card->move(originalPos5.x(), originalPos5.y());
                    alreadyClicked5 = false;
                }

                qDebug() << container4Card;

                if (container4Card == "samurai") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "samurai";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                } else if (container4Card == "kenshi") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kenshi";
                } else if (container4Card == "kyudo") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kyudo";
                } else if (container4Card == "ronin") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "ronin";
                } else if (container4Card == "strike") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "strike";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }
                } else if (container4Card == "upgrade") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card to upgrade</span></p></body></html>");
                    selectedCard = "upgrade";
                } else if (container4Card == "expell") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card from the opponent to remove</span></p></body></html>");
                    selectedCard = "expell";
                } else if (container4Card == "wager") {
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    selectedCard = "wager";

                } else if (container4Card == "fortify") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "fortify";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();

                    }

                } else if (container4Card == "blessing") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "blessing";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();

                    }


                } else if (container4Card == "diminish") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">choose an active card from the opponent to downgrade</span></p></body></html>");
                    selectedCard = "diminish";

                } else if (container4Card == "hatamoto") {
                    if(playerEnergy <= 3) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "hatamoto";
                } else if (container4Card == "shogun") {
                    if(playerEnergy <= 4) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "shogun";
                } else if (container4Card == "goshi") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "goshi";
                } else if (container4Card == "smith") {
                    selectedCard = "smith";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
            } else if (container4Card == "restore") {
                if(playerEnergy <= 0) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    selectedCard = "restore";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                }
            } else if (container4Card == "sumo") {
                if(playerEnergy <= 2) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "sumo";
                }

            }
            }

        } else if (ui->container5card->geometry().contains(event->pos())) {
            if (alreadyClicked5 == false) {
                originalPos5 = ui->container5card->pos();
                ui->container5card->move(originalPos5.x(), originalPos5.y() - 15);
                alreadyClicked5 = true;

                //move the other cards back to position so not multiple are selected
                if(alreadyClicked1 == true) {
                    ui->container1card->move(originalPos1.x(), originalPos1.y());
                    alreadyClicked1 = false;
                }
                if(alreadyClicked2 == true) {
                    ui->container2card->move(originalPos2.x(), originalPos2.y());
                    alreadyClicked2 = false;
                }
                if(alreadyClicked3 == true) {
                    ui->container3card->move(originalPos3.x(), originalPos3.y());
                    alreadyClicked3 = false;
                }
                if(alreadyClicked4 == true) {
                    ui->container4card->move(originalPos4.x(), originalPos4.y());
                    alreadyClicked4 = false;
                }

                qDebug() << container5Card;

                if (container5Card == "samurai") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "samurai";
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                } else if (container5Card == "kenshi") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kenshi";
                } else if (container5Card == "kyudo") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "kyudo";
                } else if (container5Card == "ronin") {
                    if(playerEnergy <= 1) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "ronin";
                } else if (container5Card == "strike") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else {
                        selectedCard = "strike";
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                        ui->confirmframe->raise();
                    }
                } else if (container5Card == "upgrade") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card to upgrade</span></p></body></html>");
                    selectedCard = "upgrade";
                } else if (container5Card == "expell") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">select an active card from the opponent to remove</span></p></body></html>");
                    selectedCard = "expell";
                } else if (container5Card == "wager") {
                    selectedCard = "wager";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();

                } else if (container5Card == "fortify") {
                    if(playerEnergy <= 2) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "fortify";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                } else if (container5Card == "blessing") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    selectedCard = "blessing";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();

                } else if (container5Card == "diminish") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">choose an active card from the opponent to downgrade</span></p></body></html>");
                    selectedCard = "diminish";
                } else if (container5Card == "hatamoto") {
                    if(playerEnergy <= 3) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "hatamoto";
                } else if (container5Card == "shogun") {
                    if(playerEnergy <= 4) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "shogun";
                } else if (container5Card == "goshi") {
                    if(playerEnergy <= 0) {
                        ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                    } else
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "goshi";
                } else if (container5Card == "smith") {
                    selectedCard = "smith";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
            } else if (container5Card == "restore") {
                if(playerEnergy <= 0) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    selectedCard = "restore";
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                    ui->confirmframe->raise();
                }
            } else if (container5Card == "sumo") {
                if(playerEnergy <= 2) {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">not enough energy</span></p></body></html>");
                } else {
                    ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\">click one of the three lanes to place this card</span></p></body></html>");
                    selectedCard = "sumo";
                }
                }

            }

        } else if (alreadyClicked1 == true) {
            ui->container1card->move(originalPos1);
            alreadyClicked1 = false;
            selectedCard = "";
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\"></span></p></body></html>");
        } else if (alreadyClicked2 == true) {
            ui->container2card->move(originalPos2);
            alreadyClicked2 = false;
            selectedCard = "";
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\"></span></p></body></html>");
        } else if (alreadyClicked3 == true) {
            ui->container3card->move(originalPos3);
            alreadyClicked3 = false;
            selectedCard = "";
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\"></span></p></body></html>");
        } else if (alreadyClicked4 == true) {
            ui->container4card->move(originalPos4);
            alreadyClicked4 = false;
            selectedCard = "";
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\"></span></p></body></html>");
        } else if (alreadyClicked5 == true) {
            ui->container5card->move(originalPos5);
            alreadyClicked5 = false;
            selectedCard = "";
            ui->cardguide->setText("<html><head/><body><p align=\"center\"><span style=\" font-family:'Darumadrop One'; font-size:14pt; color:#bc002d;\"></span></p></body></html>");
        }
    }


    if (event->button() == Qt::LeftButton) {
    if (ui->container1card_2->geometry().contains(event->pos())) {
        qDebug() << cardsArray[0];
        if (cardsArray[0] != "" && cardsChosen < 2) {
            QString qstr = cardsArray[0];
            string str = qstr.toStdString();
            cardStorage.push_back(str);
            cardsArray[0] = "";

            ui->container1card_2->setPixmap(QPixmap());
            cardsChosen++;
            if (cardsChosen == 2) {
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                cardsArray[0] = "";
                cardsArray[1] = "";
                cardsArray[2] = "";
                cardsArray[3] = "";
                cardsArray[4] = "";


            }


        }


    } else if (ui->container1card_3->geometry().contains(event->pos())) {
        if (cardsArray[1] != "" && cardsChosen < 2) {
            QString qstr = cardsArray[1];
            string str = qstr.toStdString();
            cardStorage.push_back(str);
            cardsArray[1] = "";
            ui->container1card_3->setPixmap(QPixmap());
            cardsChosen++;
            if (cardsChosen == 2) {
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                cardsArray[0] = "";
                cardsArray[1] = "";
                cardsArray[2] = "";
                cardsArray[3] = "";
                cardsArray[4] = "";


            }
        }
    } else if (ui->container1card_4->geometry().contains(event->pos())) {
        if (cardsArray[2] != "" && cardsChosen < 2) {
            QString qstr = cardsArray[2];
            string str = qstr.toStdString();
            cardStorage.push_back(str);
            cardsArray[2] = "";
            ui->container1card_4->setPixmap(QPixmap());
            cardsChosen++;
            if (cardsChosen == 2) {
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                cardsArray[0] = "";
                cardsArray[1] = "";
                cardsArray[2] = "";
                cardsArray[3] = "";
                cardsArray[4] = "";

            }
        }
    } else if (ui->container1card_5->geometry().contains(event->pos())) {
        if (cardsArray[3] != "" && cardsChosen < 2) {
            QString qstr = cardsArray[3];
            string str = qstr.toStdString();
            cardStorage.push_back(str);
            cardsArray[3] = "";
            ui->container1card_5->setPixmap(QPixmap());
            cardsChosen++;
            if (cardsChosen == 2) {
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                cardsArray[0] = "";
                cardsArray[1] = "";
                cardsArray[2] = "";
                cardsArray[3] = "";
                cardsArray[4] = "";
            }


        }
    } else if (ui->container1card_2->geometry().contains(event->pos())) {
        if (cardsArray[4] != "" && cardsChosen < 2) {
            QString qstr = cardsArray[4];
            string str = qstr.toStdString();
            cardStorage.push_back(str);
            cardsArray[4] = "";
            ui->container1card_2->setPixmap(QPixmap());
            cardsChosen++;
            if (cardsChosen == 2) {
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_3->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_4->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_5->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->container1card_2->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                ui->pickthecardtitle->lower();
                cardsArray[0] = "";
                cardsArray[1] = "";
                cardsArray[2] = "";
                cardsArray[3] = "";
                cardsArray[4] = "";
            }
            }
        }
    }
}


void MainWindow::on_oppnext_clicked()
{
    if (oppinfo < 10) {
        oppinfo++;
        if (oppinfo == 1) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/1.png"));
        } else if (oppinfo == 2) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/2.png"));
        } else if (oppinfo == 3) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/3.png"));
        } else if (oppinfo == 4) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/4.png"));
        } else if (oppinfo == 5) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/5.png"));
        } else if (oppinfo == 6) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/6.png"));
        } else if (oppinfo == 7) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/7.png"));
        } else if (oppinfo == 8) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/8.png"));
        } else if (oppinfo == 9) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/9.png"));
        } else if (oppinfo == 10) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/10.png"));
        }
    }

}


void MainWindow::on_oppback_clicked()
{
    if (oppinfo > 1) {
        oppinfo--;
        if (oppinfo == 1) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/1.png"));
        } else if (oppinfo == 2) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/2.png"));
        } else if (oppinfo == 3) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/3.png"));
        } else if (oppinfo == 4) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/4.png"));
        } else if (oppinfo == 5) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/5.png"));
        } else if (oppinfo == 6) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/6.png"));
        } else if (oppinfo == 7) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/7.png"));
        } else if (oppinfo == 8) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/8.png"));
        } else if (oppinfo == 9) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/9.png"));
        } else if (oppinfo == 10) {
            ui->oppdisplay->setPixmap(QPixmap(":/images/10.png"));
        }
    }

}


void MainWindow::on_gobackinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}


void MainWindow::on_info_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

