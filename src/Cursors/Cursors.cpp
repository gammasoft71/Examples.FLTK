#include <initializer_list>
#include <utility>
#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Window.H>
#include "Fl_Test_Cursor.H"

using namespace std;

class Form : public Fl_Window {
public:
  Form() : Fl_Window(200, 100, 360, 240, "ListBox example") {
    resizable(this);
    for (auto item : initializer_list<pair<const char *, Fl_Cursor>> {{"Arrow", FL_CURSOR_ARROW}, {"Cross", FL_CURSOR_CROSS}, {"Default", FL_CURSOR_DEFAULT}, {"East", FL_CURSOR_E}, {"Hand", FL_CURSOR_HAND}, {"Help", FL_CURSOR_HELP}, {"Insert", FL_CURSOR_INSERT}, {"Move", FL_CURSOR_MOVE}, {"North", FL_CURSOR_N}, {"North east",FL_CURSOR_NE}, {"North south", FL_CURSOR_NS}, {"North west", FL_CURSOR_NW}, {"North-west south-east", FL_CURSOR_NWSE}, {"South", FL_CURSOR_S}, {"South west", FL_CURSOR_SW}, {"West", FL_CURSOR_W}, {"West east", FL_CURSOR_WE}, {"Wait", FL_CURSOR_WAIT}})
      listBoxCursors.add(item.first, (void*)item.second);
    listBoxCursors.type(FL_HOLD_BROWSER);
    listBoxCursors.select(3);
    listBoxCursors.callback([](Fl_Widget* sender, void* form) {
      if (((Form*)form)->listBoxCursors.value() != 0)
        ((Form*)form)->test_zone.cursor((Fl_Cursor)(intptr_t)((Form*)form)->listBoxCursors.data(((Form*)form)->listBoxCursors.value()));
    }, this);

    test_zone.box(FL_DOWN_BOX);
    test_zone.color(FL_BACKGROUND2_COLOR);
  }
  
private:
  Fl_Browser listBoxCursors {20, 20, 150, 200};
  Fl_Window test_zone {190, 20, 150, 200};
};

int main(int argc, char *argv[]) {
  Form form;
  form.show(argc, argv);
  Fl::add_handler([](int event)->int {return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;});
  return Fl::run();
}
