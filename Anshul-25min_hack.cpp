#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class CarbonFootprintCalculator : public QWidget {
    Q_OBJECT

public:
    CarbonFootprintCalculator(QWidget *parent = nullptr);

private slots:
    void calculateFootprint();

private:
    QComboBox *transportComboBox;
    QLineEdit *distanceLineEdit;
    QComboBox *electricityComboBox;
    QLineEdit *unitsLineEdit;
    QComboBox *foodComboBox;
    QLineEdit *foodLineEdit;
};

CarbonFootprintCalculator::CarbonFootprintCalculator(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Choose the mode of transport you use for commute daily:"));
    transportComboBox = new QComboBox();
    transportComboBox->addItems({"Car(Petrol)", "Car(Diesel)", "Bus", "Train"});
    layout->addWidget(transportComboBox);
    distanceLineEdit = new QLineEdit();
    distanceLineEdit->setPlaceholderText("Enter distance in kilometers");
    layout->addWidget(distanceLineEdit);

    layout->addWidget(new QLabel("Choose the kind of electricity you use:"));
    electricityComboBox = new QComboBox();
    electricityComboBox->addItems({"Electricity (Coal-based)", "Electricity (Natural Gas)", "Electricity (Renewable)"});
    layout->addWidget(electricityComboBox);
    unitsLineEdit = new QLineEdit();
    unitsLineEdit->setPlaceholderText("Enter number of units");
    layout->addWidget(unitsLineEdit);

    layout->addWidget(new QLabel("Choose the kind of food you eat:"));
    foodComboBox = new QComboBox();
    foodComboBox->addItems({"Beef", "Chicken", "Dairy", "Vegetables", "Rice"});
    layout->addWidget(foodComboBox);
    foodLineEdit = new QLineEdit();
    foodLineEdit->setPlaceholderText("Enter amount in kg");
    layout->addWidget(foodLineEdit);

    QPushButton *calculateButton = new QPushButton("Calculate Carbon Footprint");
    layout->addWidget(calculateButton);
    connect(calculateButton, &QPushButton::clicked, this, &CarbonFootprintCalculator::calculateFootprint);
}

void CarbonFootprintCalculator::calculateFootprint() {
    float totalCO2 = 0;
    float distance = distanceLineEdit->text().toFloat();
    float units = unitsLineEdit->text().toFloat();
    float food = foodLineEdit->text().toFloat();

    // Transport
    switch (transportComboBox->currentIndex()) {
        case 0: totalCO2 += 0.12 * distance; break;
        case 1: totalCO2 += 0.14 * distance; break;
        case 2: totalCO2 += 0.05 * distance; break;
        case 3: totalCO2 += 0.04 * distance; break;
    }

    // Electricity
    switch (electricityComboBox->currentIndex()) {
        case 0: totalCO2 += 0.92 * units; break;
        case 1: totalCO2 += 0.45 * units; break;
        case 2: totalCO2 += 0.05 * units; break;
    }

    // Food
    switch (foodComboBox->currentIndex()) {
        case 0: totalCO2 += 27 * food; break;
        case 1: totalCO2 += 6.9 * food; break;
        case 2: totalCO2 += 3.2 * food; break;
        case 3: totalCO2 += 0.05 * food; break;
        case 4: totalCO2 += 4 * food; break;
    }

    QMessageBox::information(this, "Carbon Footprint", "Your daily total carbon footprint is: " + QString::number(totalCO2) + " kg of CO2");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CarbonFootprintCalculator calculator;
    calculator.show();
    return app.exec();
}

#include "Anshul-25min_hack.moc"