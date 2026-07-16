#include "musicslide.h"
#include "ui_musicslide.h"

MusicSlide::MusicSlide(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicSlide)
{
    ui->setupUi(this);
}

MusicSlide::~MusicSlide()
{
    delete ui;
}
