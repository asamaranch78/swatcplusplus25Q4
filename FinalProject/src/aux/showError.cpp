#include "showError.h"
#include "constants.h"
#include "popUpWindow.h"
#include <memory>
#include <unistd.h>

std::size_t longest_length(const std::vector<std::string>& v);
std::vector<std::string> combine(
    const std::vector<std::string>& a,
    const std::vector<std::string>& b);

void showError (std::vector<std::string> msg, std::shared_ptr<MainWindow> mainWin) {
    std::vector<std::string> textDisplayed {};
    textDisplayed = combine(msg, COMMON_TEXT);
    uint16_t size = textDisplayed.size();
    size_t width;

    width = longest_length(textDisplayed) + 10;

    PopUpWindow popUp(size + 4, width, ERROR_COLOR, mainWin);

    for (uint16_t i = 0; i < size; i++) {
        popUp.print(i+2, 5, textDisplayed.at(i));
    }
    popUp.putOnTop();
    popUp.refresh();
    sleep(1);
    wgetch(popUp.window);
    popUp.hide();
    mainWin->refresh();
}

void showError (std::string msg, std::shared_ptr<MainWindow> mainWin) {
    auto message = std::vector<std::string>(
        std::initializer_list<std::string>{msg});
    showError(message, mainWin);
}

std::size_t longest_length(const std::vector<std::string>& v) {
    std::size_t max_len = 0;

    for (const auto& s : v) {
        if (s.size() > max_len)
            max_len = s.size();
    }
    return max_len;
}


std::vector<std::string> combine(
    const std::vector<std::string>& a,
    const std::vector<std::string>& b)
{
    std::vector<std::string> result;
    result.reserve(a.size() + b.size());

    std::copy(a.begin(), a.end(), std::back_inserter(result));
    std::copy(b.begin(), b.end(), std::back_inserter(result));

    return result;
}

