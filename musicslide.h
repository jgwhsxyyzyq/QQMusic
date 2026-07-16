#ifndef MUSICSLIDE_H
#define MUSICSLIDE_H

#include <QWidget>

namespace Ui {
class MusicSlide;
}

class MusicSlide : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlide(QWidget *parent = nullptr);
    ~MusicSlide();

private:
    Ui::MusicSlide *ui;
};

#endif // MUSICSLIDE_H
