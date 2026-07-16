/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <btform.h>
#include <commonpage.h>
#include <musicslide.h>
#include <recbox.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *background;
    QVBoxLayout *verticalLayout_2;
    QWidget *head;
    QHBoxLayout *horizontalLayout;
    QWidget *headLeft;
    QHBoxLayout *horizontalLayout_3;
    QLabel *logo;
    QWidget *headRight;
    QHBoxLayout *horizontalLayout_4;
    QWidget *searchBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QWidget *settingBox;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QPushButton *max;
    QPushButton *min;
    QPushButton *quit;
    QWidget *body;
    QHBoxLayout *horizontalLayout_6;
    QWidget *bodyLeft;
    QVBoxLayout *verticalLayout_3;
    QWidget *letfBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *onlineMusic;
    QVBoxLayout *verticalLayout_5;
    QLabel *onlineMusicText;
    BtForm *rec;
    BtForm *radio;
    BtForm *music;
    QWidget *myMusic;
    QVBoxLayout *verticalLayout_6;
    QLabel *myLabelText;
    BtForm *like;
    BtForm *local;
    BtForm *recent;
    QSpacerItem *verticalSpacer;
    QWidget *bodyRight;
    QVBoxLayout *verticalLayout_7;
    QStackedWidget *stackedWidget;
    QWidget *recPage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *recText;
    QLabel *recMusictext;
    RecBox *recMusicBox;
    QLabel *supplyMusicText;
    RecBox *supplyMusicBox;
    QWidget *musicPage;
    QWidget *radioPage;
    CommonPage *likePage;
    CommonPage *localPage;
    CommonPage *recentPage;
    MusicSlide *processBar;
    QWidget *controlBox;
    QHBoxLayout *horizontalLayout_7;
    QWidget *play_1;
    QGridLayout *gridLayout;
    QLabel *musicName;
    QLabel *musicSinger;
    QLabel *musicCover;
    QWidget *play_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *playMode;
    QPushButton *playUp;
    QPushButton *play;
    QPushButton *playDown;
    QPushButton *volume;
    QPushButton *addLocal;
    QWidget *play_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelNull;
    QLabel *currenTime;
    QLabel *line;
    QLabel *totalTime;
    QPushButton *lrcWord;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1040, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        background = new QWidget(Widget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(background);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        head = new QWidget(background);
        head->setObjectName(QString::fromUtf8("head"));
        head->setMinimumSize(QSize(0, 80));
        head->setMaximumSize(QSize(16777215, 80));
        head->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(head);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        headLeft = new QWidget(head);
        headLeft->setObjectName(QString::fromUtf8("headLeft"));
        headLeft->setMinimumSize(QSize(200, 0));
        headLeft->setMaximumSize(QSize(200, 16777215));
        headLeft->setStyleSheet(QString::fromUtf8("#headLeft\n"
"{\n"
"    background-color: #F0F0F0; /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\346\265\205\347\201\260\350\211\262 */\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(headLeft);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        logo = new QLabel(headLeft);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setStyleSheet(QString::fromUtf8("#logo{\n"
"	border-radius:0px;\n"
"	background-image:url(:/images/Logo.png);\n"
"	background-repeat:no-repeat;\n"
"	border:none;\n"
"	background-position:center 	center;\n"
"}"));

        horizontalLayout_3->addWidget(logo);


        horizontalLayout->addWidget(headLeft);

        headRight = new QWidget(head);
        headRight->setObjectName(QString::fromUtf8("headRight"));
        headRight->setStyleSheet(QString::fromUtf8("\n"
"#headRight\n"
"{\n"
"	background-color:#f5f5f5;/*\344\272\256\347\201\260\350\211\262*/\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(headRight);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        searchBox = new QWidget(headRight);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setMinimumSize(QSize(300, 0));
        searchBox->setMaximumSize(QSize(300, 16777215));
        searchBox->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;"));
        verticalLayout = new QVBoxLayout(searchBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 0, 0);
        lineEdit = new QLineEdit(searchBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 35));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
"{\n"
"   background-color:#E3E3E3;\n"
"	border-radius:17px;\n"
"	padding-left:17px;\n"
"	border: none;\n"
"\n"
"}\n"
"\n"
""));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout_4->addWidget(searchBox);

        settingBox = new QWidget(headRight);
        settingBox->setObjectName(QString::fromUtf8("settingBox"));
        settingBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none;\n"
"	border-radius:0px;\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
" background-color: rgba(230,0,0,0.5); /*\350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\n"
"\342\276\212\344\270\272\345\215\212\351\200\217\346\230\216\347\232\204\347\272\242\342\276\212*/\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(settingBox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(405, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        skin = new QPushButton(settingBox);
        skin->setObjectName(QString::fromUtf8("skin"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(skin->sizePolicy().hasHeightForWidth());
        skin->setSizePolicy(sizePolicy1);
        skin->setMinimumSize(QSize(30, 30));
        skin->setMaximumSize(QSize(30, 30));
        skin->setStyleSheet(QString::fromUtf8("#skin{\n"
"	background-image:url(:/images/skin.png);\n"
"	\n"
"	\n"
"}"));

        horizontalLayout_5->addWidget(skin);

        max = new QPushButton(settingBox);
        max->setObjectName(QString::fromUtf8("max"));
        sizePolicy1.setHeightForWidth(max->sizePolicy().hasHeightForWidth());
        max->setSizePolicy(sizePolicy1);
        max->setMinimumSize(QSize(30, 30));
        max->setMaximumSize(QSize(30, 30));
        max->setStyleSheet(QString::fromUtf8("#max{\n"
"	\n"
"	background-image:url(:/images/max.png);\n"
"\n"
"	\n"
"	\n"
"}\n"
""));

        horizontalLayout_5->addWidget(max);

        min = new QPushButton(settingBox);
        min->setObjectName(QString::fromUtf8("min"));
        sizePolicy1.setHeightForWidth(min->sizePolicy().hasHeightForWidth());
        min->setSizePolicy(sizePolicy1);
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("#min{\n"
"  \n"
"    background-image: url(:/images/min.png);\n"
"  \n"
"\n"
"}"));

        horizontalLayout_5->addWidget(min);

        quit = new QPushButton(settingBox);
        quit->setObjectName(QString::fromUtf8("quit"));
        sizePolicy1.setHeightForWidth(quit->sizePolicy().hasHeightForWidth());
        quit->setSizePolicy(sizePolicy1);
        quit->setMinimumSize(QSize(30, 30));
        quit->setMaximumSize(QSize(30, 30));
        quit->setStyleSheet(QString::fromUtf8("#quit{\n"
"\n"
"	background-image:url(:/images/quit.png);\n"
"}"));

        horizontalLayout_5->addWidget(quit);


        horizontalLayout_4->addWidget(settingBox);


        horizontalLayout->addWidget(headRight);


        verticalLayout_2->addWidget(head);

        body = new QWidget(background);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(body);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        bodyLeft = new QWidget(body);
        bodyLeft->setObjectName(QString::fromUtf8("bodyLeft"));
        bodyLeft->setMinimumSize(QSize(200, 0));
        bodyLeft->setMaximumSize(QSize(200, 16777215));
        bodyLeft->setStyleSheet(QString::fromUtf8("#bodyLeft\n"
"{\n"
" background-color:#F0F0F0;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(bodyLeft);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        letfBox = new QWidget(bodyLeft);
        letfBox->setObjectName(QString::fromUtf8("letfBox"));
        letfBox->setMinimumSize(QSize(0, 400));
        letfBox->setMaximumSize(QSize(16777215, 400));
        letfBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(letfBox);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        onlineMusic = new QWidget(letfBox);
        onlineMusic->setObjectName(QString::fromUtf8("onlineMusic"));
        onlineMusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(onlineMusic);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        onlineMusicText = new QLabel(onlineMusic);
        onlineMusicText->setObjectName(QString::fromUtf8("onlineMusicText"));

        verticalLayout_5->addWidget(onlineMusicText);

        rec = new BtForm(onlineMusic);
        rec->setObjectName(QString::fromUtf8("rec"));
        rec->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(rec);

        radio = new BtForm(onlineMusic);
        radio->setObjectName(QString::fromUtf8("radio"));
        radio->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(radio);

        music = new BtForm(onlineMusic);
        music->setObjectName(QString::fromUtf8("music"));
        music->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(music);


        verticalLayout_4->addWidget(onlineMusic);

        myMusic = new QWidget(letfBox);
        myMusic->setObjectName(QString::fromUtf8("myMusic"));
        myMusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(myMusic);
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(6, 6, 6, 4);
        myLabelText = new QLabel(myMusic);
        myLabelText->setObjectName(QString::fromUtf8("myLabelText"));

        verticalLayout_6->addWidget(myLabelText);

        like = new BtForm(myMusic);
        like->setObjectName(QString::fromUtf8("like"));
        like->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(like);

        local = new BtForm(myMusic);
        local->setObjectName(QString::fromUtf8("local"));
        local->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(local);

        recent = new BtForm(myMusic);
        recent->setObjectName(QString::fromUtf8("recent"));
        recent->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(recent);


        verticalLayout_4->addWidget(myMusic);


        verticalLayout_3->addWidget(letfBox);

        verticalSpacer = new QSpacerItem(20, 205, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(bodyLeft);

        bodyRight = new QWidget(body);
        bodyRight->setObjectName(QString::fromUtf8("bodyRight"));
        bodyRight->setStyleSheet(QString::fromUtf8("#bodyRight{\n"
"	background-color:#F5F5F5;\n"
"	\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(bodyRight);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 5, 0);
        stackedWidget = new QStackedWidget(bodyRight);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        recPage = new QWidget();
        recPage->setObjectName(QString::fromUtf8("recPage"));
        scrollArea = new QScrollArea(recPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 800, 483));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(820, 500));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 798, 481));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        recText = new QLabel(scrollAreaWidgetContents_2);
        recText->setObjectName(QString::fromUtf8("recText"));
        recText->setMinimumSize(QSize(0, 50));
        recText->setMaximumSize(QSize(16777215, 50));
        QPalette palette;
        QBrush brush(QColor(255, 192, 203, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 192, 203, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        recText->setPalette(palette);
        QFont font;
        font.setPointSize(24);
        recText->setFont(font);

        verticalLayout_8->addWidget(recText);

        recMusictext = new QLabel(scrollAreaWidgetContents_2);
        recMusictext->setObjectName(QString::fromUtf8("recMusictext"));
        recMusictext->setMinimumSize(QSize(0, 30));
        recMusictext->setMaximumSize(QSize(16777215, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        recMusictext->setPalette(palette1);
        QFont font1;
        font1.setPointSize(18);
        recMusictext->setFont(font1);

        verticalLayout_8->addWidget(recMusictext);

        recMusicBox = new RecBox(scrollAreaWidgetContents_2);
        recMusicBox->setObjectName(QString::fromUtf8("recMusicBox"));

        verticalLayout_8->addWidget(recMusicBox);

        supplyMusicText = new QLabel(scrollAreaWidgetContents_2);
        supplyMusicText->setObjectName(QString::fromUtf8("supplyMusicText"));
        supplyMusicText->setMinimumSize(QSize(0, 30));
        supplyMusicText->setMaximumSize(QSize(16777215, 30));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        supplyMusicText->setPalette(palette2);
        supplyMusicText->setFont(font1);

        verticalLayout_8->addWidget(supplyMusicText);

        supplyMusicBox = new RecBox(scrollAreaWidgetContents_2);
        supplyMusicBox->setObjectName(QString::fromUtf8("supplyMusicBox"));

        verticalLayout_8->addWidget(supplyMusicBox);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(recPage);
        musicPage = new QWidget();
        musicPage->setObjectName(QString::fromUtf8("musicPage"));
        stackedWidget->addWidget(musicPage);
        radioPage = new QWidget();
        radioPage->setObjectName(QString::fromUtf8("radioPage"));
        stackedWidget->addWidget(radioPage);
        likePage = new CommonPage();
        likePage->setObjectName(QString::fromUtf8("likePage"));
        stackedWidget->addWidget(likePage);
        localPage = new CommonPage();
        localPage->setObjectName(QString::fromUtf8("localPage"));
        stackedWidget->addWidget(localPage);
        recentPage = new CommonPage();
        recentPage->setObjectName(QString::fromUtf8("recentPage"));
        stackedWidget->addWidget(recentPage);

        verticalLayout_7->addWidget(stackedWidget);

        processBar = new MusicSlide(bodyRight);
        processBar->setObjectName(QString::fromUtf8("processBar"));
        processBar->setMinimumSize(QSize(0, 30));
        processBar->setMaximumSize(QSize(16777215, 30));
        processBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(processBar);

        controlBox = new QWidget(bodyRight);
        controlBox->setObjectName(QString::fromUtf8("controlBox"));
        controlBox->setMinimumSize(QSize(0, 60));
        controlBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(controlBox);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        play_1 = new QWidget(controlBox);
        play_1->setObjectName(QString::fromUtf8("play_1"));
        play_1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(play_1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        musicName = new QLabel(play_1);
        musicName->setObjectName(QString::fromUtf8("musicName"));

        gridLayout->addWidget(musicName, 0, 2, 1, 1);

        musicSinger = new QLabel(play_1);
        musicSinger->setObjectName(QString::fromUtf8("musicSinger"));

        gridLayout->addWidget(musicSinger, 1, 2, 1, 1);

        musicCover = new QLabel(play_1);
        musicCover->setObjectName(QString::fromUtf8("musicCover"));
        musicCover->setStyleSheet(QString::fromUtf8("#musicCover\n"
"{\n"
"    color: #333333; /* \350\277\231\351\207\214\344\277\256\346\224\271\350\211\262\345\200\274\357\274\214\346\216\247\345\210\266\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}"));

        gridLayout->addWidget(musicCover, 0, 1, 1, 1);


        horizontalLayout_7->addWidget(play_1);

        play_2 = new QWidget(controlBox);
        play_2->setObjectName(QString::fromUtf8("play_2"));
        play_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" border: none; \n"
"background-repeat:no-repeat;\n"
" background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
" background-color: rgba(230,0,0,0.5); \n"
"\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(play_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        playMode = new QPushButton(play_2);
        playMode->setObjectName(QString::fromUtf8("playMode"));
        playMode->setMinimumSize(QSize(30, 30));
        playMode->setMaximumSize(QSize(30, 30));
        playMode->setStyleSheet(QString::fromUtf8("#playMode{\n"
"	background-image:url(:/images/shuffle_2.png)\n"
"}\n"
"\n"
""));

        horizontalLayout_8->addWidget(playMode);

        playUp = new QPushButton(play_2);
        playUp->setObjectName(QString::fromUtf8("playUp"));
        playUp->setMinimumSize(QSize(30, 30));
        playUp->setMaximumSize(QSize(30, 30));
        playUp->setStyleSheet(QString::fromUtf8("#playUp\n"
"{\n"
" background-image: url(:/images/up.png);\n"
"}"));

        horizontalLayout_8->addWidget(playUp);

        play = new QPushButton(play_2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(30, 30));
        play->setMaximumSize(QSize(30, 30));
        play->setStyleSheet(QString::fromUtf8("#play\n"
"{\n"
" background-image: url(:/images/play3.png);\n"
"}"));

        horizontalLayout_8->addWidget(play);

        playDown = new QPushButton(play_2);
        playDown->setObjectName(QString::fromUtf8("playDown"));
        playDown->setMinimumSize(QSize(30, 30));
        playDown->setMaximumSize(QSize(30, 30));
        playDown->setStyleSheet(QString::fromUtf8("#playDown{\n"
"\n"
"	background-image:url(:/images/down.png);\n"
"	}"));

        horizontalLayout_8->addWidget(playDown);

        volume = new QPushButton(play_2);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMinimumSize(QSize(30, 30));
        volume->setMaximumSize(QSize(30, 30));
        volume->setStyleSheet(QString::fromUtf8("#volume{\n"
"	background-image:url(:/images/volumn.png);\n"
"}"));

        horizontalLayout_8->addWidget(volume);

        addLocal = new QPushButton(play_2);
        addLocal->setObjectName(QString::fromUtf8("addLocal"));
        addLocal->setMinimumSize(QSize(30, 30));
        addLocal->setMaximumSize(QSize(30, 30));
        addLocal->setStyleSheet(QString::fromUtf8("#addLocal{\n"
"	background-image:url(:/images/add.png)\n"
"}"));

        horizontalLayout_8->addWidget(addLocal);


        horizontalLayout_7->addWidget(play_2);

        play_3 = new QWidget(controlBox);
        play_3->setObjectName(QString::fromUtf8("play_3"));
        play_3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_9 = new QHBoxLayout(play_3);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        labelNull = new QLabel(play_3);
        labelNull->setObjectName(QString::fromUtf8("labelNull"));

        horizontalLayout_9->addWidget(labelNull);

        currenTime = new QLabel(play_3);
        currenTime->setObjectName(QString::fromUtf8("currenTime"));

        horizontalLayout_9->addWidget(currenTime);

        line = new QLabel(play_3);
        line->setObjectName(QString::fromUtf8("line"));

        horizontalLayout_9->addWidget(line);

        totalTime = new QLabel(play_3);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));

        horizontalLayout_9->addWidget(totalTime);

        lrcWord = new QPushButton(play_3);
        lrcWord->setObjectName(QString::fromUtf8("lrcWord"));
        lrcWord->setMinimumSize(QSize(30, 30));
        lrcWord->setMaximumSize(QSize(30, 30));
        lrcWord->setStyleSheet(QString::fromUtf8("#lrcWord{\n"
"	border:none;\n"
"	background-repeat:no-repeat;\n"
"	background-position:center center;\n"
"	\n"
"    color: #333333; \n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
" background-color: rgba(230,0,0,0.5); \n"
"\n"
"}"));
        lrcWord->setCheckable(false);

        horizontalLayout_9->addWidget(lrcWord);


        horizontalLayout_7->addWidget(play_3);


        verticalLayout_7->addWidget(controlBox);


        horizontalLayout_6->addWidget(bodyRight);


        verticalLayout_2->addWidget(body);


        horizontalLayout_2->addWidget(background);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        logo->setText(QString());
        skin->setText(QString());
        max->setText(QString());
        min->setText(QString());
        quit->setText(QString());
        onlineMusicText->setText(QCoreApplication::translate("Widget", "\345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        myLabelText->setText(QCoreApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", nullptr));
        recText->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#000000;\">\346\216\250\350\215\220</span></p></body></html>", nullptr));
        recMusictext->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#000000;\">\344\273\212\346\227\245\344\270\272\344\275\240\346\216\250\350\215\220</span></p></body></html>", nullptr));
        supplyMusicText->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" color:#000000;\">\344\275\240\347\232\204\351\237\263\344\271\220\350\241\245\347\273\231\347\253\231</span></p></body></html>", nullptr));
        musicName->setText(QCoreApplication::translate("Widget", "gs", nullptr));
        musicSinger->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        musicCover->setText(QCoreApplication::translate("Widget", "\345\233\276\347\211\207", nullptr));
        playMode->setText(QString());
        playUp->setText(QString());
        play->setText(QString());
        playDown->setText(QString());
        volume->setText(QString());
        addLocal->setText(QString());
        labelNull->setText(QString());
        currenTime->setText(QString());
        line->setText(QString());
        totalTime->setText(QString());
        lrcWord->setText(QCoreApplication::translate("Widget", "\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
