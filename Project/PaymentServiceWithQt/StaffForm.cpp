#include "StaffForm.h"
#include <QHeaderView>
#include "PaymentServiceWithQt.h"

StaffForm::StaffForm(QWidget *parent) : 
    QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));

	// Buttons
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	ui.tableWidget->setRowCount(40);
	ui.tableWidget->setColumnCount(3);

	QStringList labels;
	labels << "Username" << "Email" << "Status";
	ui.tableWidget->setHorizontalHeaderLabels(labels);

	for (int i = 0; i < ui.tableWidget->rowCount(); i++) {
		QTableWidgetItem* item;
		for (int j = 0; j < ui.tableWidget->columnCount(); j++) {
			item = new QTableWidgetItem;
			item->setText("Name" + QString::number(i));
			ui.tableWidget->setItem(i, j, item);
			ui.tableWidget->item(i, j)->setTextAlignment(Qt::AlignCenter);
		}
	}

	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setTextElideMode(Qt::ElideRight);
	ui.tableWidget->setSortingEnabled(true);
	ui.tableWidget->setShowGrid(false);


	ui.tableWidget->horizontalHeader()->setVisible(true);
	ui.tableWidget->horizontalHeader()->setDefaultSectionSize(200);	
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.tableWidget->verticalHeader()->setVisible(false);
	


}

StaffForm::~StaffForm()
{
}

void StaffForm::logOut() {
	PaymentServiceWithQt* entry = new PaymentServiceWithQt();
	entry->show();
	close();
}
