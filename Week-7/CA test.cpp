#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QPalette>

class ScrambleGame : public QWidget {
    Q_OBJECT

public:
    ScrambleGame(QWidget *parent = nullptr);
    
private slots:
    void onGetLetterClicked();
    void onGuessWord();
    void onNextWord();
    void onHintClicked();

private:
    void scrambleWord();
    void displayWord();
    void showMessage(const QString& message, const QColor& color);

    QList<QString> words = {"apple", "banana", "grape", "cherry", "orange"};
    QString currentWord;
    QString scrambledWord;
    QString correctWord;
    int remainingAttempts;
    int currentWordIndex;
    QString hint;
    QLabel *scrambledLabel;
    QLabel *messageLabel;
    QLineEdit *guessInput;
    QPushButton *getLetterButton;
    QPushButton *nextButton;
    QPushButton *hintButton;
};

ScrambleGame::ScrambleGame(QWidget *parent) : QWidget(parent), currentWordIndex(0), remainingAttempts(5) {
    setWindowTitle("Scramble Word Game");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    scrambledLabel = new QLabel("Scrambled Word: ", this);
    mainLayout->addWidget(scrambledLabel);

    guessInput = new QLineEdit(this);
    mainLayout->addWidget(guessInput);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    getLetterButton = new QPushButton("GET LETTER", this);
    buttonLayout->addWidget(getLetterButton);

    hintButton = new QPushButton("HINT", this);
    buttonLayout->addWidget(hintButton);

    nextButton = new QPushButton("NEXT", this);
    buttonLayout->addWidget(nextButton);

    mainLayout->addLayout(buttonLayout);

    messageLabel = new QLabel("", this);
    mainLayout->addWidget(messageLabel);

    connect(getLetterButton, &QPushButton::clicked, this, &ScrambleGame::onGetLetterClicked);
    connect(nextButton, &QPushButton::clicked, this, &ScrambleGame::onNextWord);
    connect(hintButton, &QPushButton::clicked, this, &ScrambleGame::onHintClicked);

    scrambleWord();
}

void ScrambleGame::scrambleWord() {
    currentWord = words[currentWordIndex];
    correctWord = currentWord;
    scrambledWord = currentWord;
    remainingAttempts = 5;

    // Scramble the word
    for (int i = scrambledWord.length() - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1);
        std::swap(scrambledWord[i], scrambledWord[j]);
    }

    hint = QString("First letter: %1").arg(currentWord[0]);
    displayWord();
}

void ScrambleGame::displayWord() {
    scrambledLabel->setText("Scrambled Word: " + scrambledWord);
    messageLabel->clear();
}

void ScrambleGame::onGetLetterClicked() {
    if (remainingAttempts > 0) {
        remainingAttempts--;

        // Reveal a correct letter (based on the number of remaining attempts)
        QString revealedWord = scrambledWord;
        int indexToReveal = scrambledWord.indexOf('_');
        if (indexToReveal != -1) {
            revealedWord[indexToReveal] = correctWord[indexToReveal];
        }
        scrambledLabel->setText("Scrambled Word: " + revealedWord);

        if (remainingAttempts == 0) {
            showMessage("No more attempts!", Qt::red);
        }
    }
}

void ScrambleGame::onGuessWord() {
    if (guessInput->text().toLower() == correctWord) {
        showMessage("You guessed the word correctly!", Qt::blue);
        remainingAttempts++;
    } else {
        showMessage("Incorrect guess. Try again!", Qt::red);
    }
}

void ScrambleGame::onNextWord() {
    currentWordIndex++;
    if (currentWordIndex < words.size()) {
        scrambleWord();
    } else {
        showMessage("This is the last word!", Qt::red);
    }
}

void ScrambleGame::onHintClicked() {
    showMessage(hint, Qt::green);
}

void ScrambleGame::showMessage(const QString& message, const QColor& color) {
    QPalette palette;
    palette.setColor(QPalette::WindowText, color);
    messageLabel->setPalette(palette);
    messageLabel->setText(message);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ScrambleGame game;
    game.show();

    return app.exec();
}

#include "main.moc"
