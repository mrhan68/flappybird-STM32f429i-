#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void BirdUp();
    void aaaa();
    void handleTickEvent();
    uint32_t t;
    uint32_t tickCount;
    uint32_t c;
    uint32_t statue;
    int v;
    uint32_t start;
    int tmp;
    int score;
protected:
};

#endif // SCREEN1VIEW_HPP
