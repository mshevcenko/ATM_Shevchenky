#include <cassert>
#include "autil.h"

#ifndef ndebug
string cardnumber1 = "2481632641282565";
string pin1 = "2222";
double basebalance1 = 10000;
time_t expday1 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;

string cardnumber2 = "4816326412825651";
string pin2 = "3333";
double basebalance2 = 10000;
time_t expday2 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;

string cardnumber3 = "8163264128256512";
string pin3 = "4444";
double basebalance3 = 500;
time_t expday3 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;


string cardnumber4 = "1632641282565121";
string pin4 = "5555";
double basebalance4 = 3000;
time_t expday4 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;

string cardnumber5 = "6326412825651210";
string pin5 = "6666";
double basebalance5 = 500;
time_t expday5 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;

string cardnumber6 = "3264128256512102";
string pin6 = "6666";
double basebalance6 = 500;
time_t expday6 = Toolbox::getCurrentDate() + Toolbox::getOneDay() * 100;

size_t bid = 0;
size_t atmid = 0;

void initValuesForTests() {
	{
		cout << boolalpha;
		Bank bb = Bank("TestBank");
		cout << "create bank " << Toolbox::getToolbox().g_BankDao().create(bb) << '\n';
		auto bbv = Toolbox::getToolbox().g_BankDao().getAll();

		for (auto it = bbv.begin(); it != bbv.end(); ++it) {
			if ((*it).name() == "TestBank") {
				bid = (*it).id();
			}
		}
		ATM aat(bid);
		aat.fillWithMoney(10);
		cout << "create atm " << ATM::createAtmWithMoneyStorage(aat) << '\n';
		atmid = Toolbox::getLastCreatedAtmIdByBank(bid);



		cout << "create card and account " << aat.createCardAndAccount(cardnumber1, pin1, basebalance1, expday1, bid) << '\n';
		cout << "create card and account " << aat.createCardAndAccount(cardnumber2, pin2, basebalance2, expday2, bid) << '\n';
		cout << "create card and account " << aat.createCardAndAccount(cardnumber3, pin3, basebalance3, expday3, bid) << '\n';
		cout << "create card and account " << aat.createCardAndAccount(cardnumber4, pin4, basebalance4, expday4, bid) << '\n';
		cout << "create card and account " << aat.createCardAndAccount(cardnumber5, pin5, basebalance5, expday5, bid) << '\n';
		cout << "create card and account " << aat.createCardAndAccount(cardnumber6, pin6, basebalance6, expday6, bid) << '\n';
	}
}

void deleteInitedData() {
	{
		auto accv = Toolbox::getToolbox().g_AccountDao().getAllByBankId(bid);
		for (auto it = accv.begin(); it != accv.end(); ++it) {
			Card* cc = Toolbox::getToolbox().g_CardDao().getByAccountId((*it).id());
			if (cc != nullptr) {
				auto ocsv = Toolbox::getToolbox().g_OverflowCreditServiceDao().getByFrom((*cc).cardNumber());
				for (auto it1 = ocsv.begin(); it1 != ocsv.end(); ++it1) {
					cout << "removed overflowCreditService " << Toolbox::getToolbox().g_OverflowCreditServiceDao().remove(*it1) << '\n';
				}
				auto osv = Toolbox::getToolbox().g_OverflowServiceDao().getByFrom((*cc).cardNumber());
				for (auto it1 = osv.begin(); it1 != osv.end(); ++it1) {
					cout << "removed overflowService " << Toolbox::getToolbox().g_OverflowServiceDao().remove(*it1) << '\n';
				}
				auto ttv = Toolbox::getToolbox().g_TransferDao().getByFrom((*cc).cardNumber());
				for (auto it1 = ttv.begin(); it1 != ttv.end(); ++it1) {
					cout << "removed transfer " << Toolbox::getToolbox().g_TransferDao().remove(*it1) << '\n';
				}
				auto wwv = Toolbox::getToolbox().g_WithdrawalServiceDao().getByFrom((*cc).cardNumber());
				for (auto it1 = wwv.begin(); it1 != wwv.end(); ++it1) {
					cout << "removed withdrawl " << Toolbox::getToolbox().g_WithdrawalServiceDao().remove(*it1) << '\n';
				}
				auto tdv = Toolbox::getToolbox().g_TransferDaemonDao().getByFrom((*cc).cardNumber());
				for (auto it1 = tdv.begin(); it1 != tdv.end(); ++it1) {
					cout << "removed withdrawl " << Toolbox::getToolbox().g_TransferDaemonDao().remove(*it1) << '\n';
				}
				cout << "removed card " << Toolbox::getToolbox().g_CardDao().remove(*cc) << '\n';
				delete cc;
			}
			cout << "removed account " << Toolbox::getToolbox().g_AccountDao().remove(*it) << '\n';
		}

		cout << "removed atm " << ATM::deleteAtmWithMoneyStorage(atmid) << '\n';
		cout << "removed bank " << Toolbox::getToolbox().g_BankDao().remove(Bank(bid)) << '\n';
	}
}

bool doingTesting() {
	{
		bool cumtest = true;
		ATM aa = copyAndDeletePointer(ATM::getAtmWithMoneyStorage(atmid));

		cumtest &= Toolbox::makeTest("insertCard1", aa.insertCard(cardnumber1, pin1));
		cumtest &= Toolbox::makeTest("checkPinCode", aa.checkPinCode(pin1));
		double transferAmountToReciev = 500;
		double transferAmountToSend = aa.calculateFeeSend(transferAmountToReciev);
		Transfer transfer1(aa.currentCardNumber(), cardnumber2, transferAmountToSend);
		cumtest &= Toolbox::makeTest("createTransfer", aa.createTransfer(transfer1));
		aa.nextDay();
		cumtest &= Toolbox::makeTest("transferAmountToReciev",
			(basebalance2 + transferAmountToReciev) == copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber2)).balance()
		);
		cumtest &= Toolbox::makeTest("transferAmountToSend",
			(basebalance1 - transferAmountToSend) == copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber1)).balance()
		);

		double overflowCreditVal = -600;
		OverflowCreditService overflowCreditService1 = OverflowCreditService("", cardnumber3, overflowCreditVal);
		cumtest &= Toolbox::makeTest("createOverflowCreditService1", aa.createOverflowCreditService(overflowCreditService1));
		aa.exit();

		cumtest &= Toolbox::makeTest("insertCard3", aa.insertCard(cardnumber3, pin3));
		double creditlinmit1 = 1000;
		cumtest &= Toolbox::makeTest("changeCreditLimit", aa.changeCreditLimit(creditlinmit1));
		cumtest &= Toolbox::makeTest("changeCreditLimitActual", creditlinmit1 == copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber3)).creditLimit());
		double transferAmountToReciev2 = 1000;
		double transferAmountToSend2 = aa.calculateFeeSend(transferAmountToReciev2);
		Transfer transfer2(aa.currentCardNumber(), cardnumber2, transferAmountToSend2);
		cumtest &= Toolbox::makeTest("createTransfer", aa.createTransfer(transfer2));
		aa.nextDay();
		cumtest &= Toolbox::makeTest("transferAmountToSend",
			(basebalance3 - transferAmountToSend2) == copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber3)).balance()
		);
		Transfer transfer3(aa.currentCardNumber(), cardnumber2, transferAmountToSend2);
		cumtest &= Toolbox::makeTest("transferAmountToSendCan_t", !aa.createTransfer(transfer3));
		aa.nextDay();

		double creditlinmit2 = 3000;
		cumtest &= Toolbox::makeTest("changeCreditLimit", aa.changeCreditLimit(creditlinmit2));
		Transfer transfer4(aa.currentCardNumber(), cardnumber2, transferAmountToReciev2);
		cumtest &= Toolbox::makeTest("transferToCredit", aa.createTransfer(transfer4));
		aa.nextDay();
		cumtest &= Toolbox::makeTest("transferToCredit", aa.createTransfer(transfer4));
		aa.nextDay();
		cumtest &= Toolbox::makeTest("OverflowCreditService",
			overflowCreditVal == copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber3)).balance()
		);
		cout << "WTF -=- " << copyAndDeletePointer(Toolbox::getToolbox().g_AccountDao().getByCardNumber(cardnumber3)).balance() << '\n';

		auto trnsfv = aa.getTransfers();
		cumtest &= Toolbox::makeTest("transferFirstRetrievedRight", trnsfv.size() == 4);

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard1", aa.insertCard(cardnumber1, pin1));
		cout << "getBalance -=- " << aa.getBalance() << '\n';
		double balanceOnCard1 = aa.getBalance();
		size_t withdrawAmount = 2357;
		cout << "withdrawing money " << withdrawAmount << '\n';
		auto currencyGiven = aa.withdraw(withdrawAmount);
		cumtest &= Toolbox::makeTest("withdraw", withdrawAmount == Toolbox::calculateSum(currencyGiven));
		for (auto it = currencyGiven.begin(); it != currencyGiven.end(); ++it) {
			cout << "cur:" << (*it).first << " - amount:" << (*it).second << '\n';
		}

		auto wthdv = aa.getWithdrawalServices();
		cumtest &= Toolbox::makeTest("withdrawalRetrievedRight", !wthdv.empty() && wthdv.front().amount() == withdrawAmount && wthdv.front().atmId() == aa.id() && wthdv.front().from() == aa.currentCardNumber());


		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard3", aa.insertCard(cardnumber3, pin3));

		double overflowCreditVal2 = 1000;
		OverflowCreditService overflowCreditService2 = OverflowCreditService("", cardnumber4, overflowCreditVal2);
		cumtest &= Toolbox::makeTest("createOverflowCreditService", aa.createOverflowCreditService(overflowCreditService2));

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard5", aa.insertCard(cardnumber5, pin5));
		double overflowVal1 = 1000;
		OverflowService overflowService1 = OverflowService("", cardnumber6, overflowVal1);
		cumtest &= Toolbox::makeTest("createOverflowService", aa.createOverflowService(overflowService1));

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard6", aa.insertCard(cardnumber6, pin6));
		double overflowVal2 = 1000;
		OverflowService overflowService2 = OverflowService("", cardnumber4, overflowVal2);
		cumtest &= Toolbox::makeTest("createOverflowService", aa.createOverflowService(overflowService2));

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard4", aa.insertCard(cardnumber4, pin4));
		double transferAmountToSend3 = 3000;
		Transfer transfer5(aa.currentCardNumber(), cardnumber5, transferAmountToSend3);
		cumtest &= Toolbox::makeTest("transferAmountToSend", aa.createTransfer(transfer5));


		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard5", aa.insertCard(cardnumber5, pin5));
		cumtest &= Toolbox::makeTest("OverflowActual1", aa.getBalance() == overflowVal1);
		cumtest &= Toolbox::makeTest("haveOverflowService", aa.hasOverflowService());
		cumtest &= Toolbox::makeTest("deleteOverflowService", aa.hasOverflowService() && aa.deleteOverflowService(aa.getOverflowService()));

		double transferDaemonAmountToSend = 100;
		TransferDaemon trd1 = TransferDaemon("", cardnumber6, aa.calculateFeeSend(transferDaemonAmountToSend), Toolbox::getCurrentDate() + Toolbox::getOneDay(), Toolbox::getOneDay() * 2, true);
		TransferDaemon trd2 = TransferDaemon("", cardnumber4, aa.calculateFeeSend(transferDaemonAmountToSend), Toolbox::getCurrentDate() + Toolbox::getOneDay(), Toolbox::getOneDay() * 2, false);

		cumtest &= Toolbox::makeTest("createTransferDaemon1", aa.createTransferDaemon(trd1));
		cumtest &= Toolbox::makeTest("createTransferDaemon2", aa.createTransferDaemon(trd2));

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard6", aa.insertCard(cardnumber6, pin6));
		cumtest &= Toolbox::makeTest("OverflowActual2", aa.getBalance() == overflowVal2);
		cumtest &= Toolbox::makeTest("haveOverflowService", aa.hasOverflowService());
		cumtest &= Toolbox::makeTest("deleteOverflowService", aa.hasOverflowService() && aa.deleteOverflowService(aa.getOverflowService()));

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard4", aa.insertCard(cardnumber4, pin4));
		cumtest &= Toolbox::makeTest("OverflowChains", aa.getBalance() > overflowCreditVal2);
		cumtest &= Toolbox::makeTest("haven_tOverflowService", !aa.hasOverflowService());
		double balanceOnCard4 = aa.getBalance();

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard3", aa.insertCard(cardnumber3, pin3));
		auto ocsvtt = aa.getOverflowCreditServices();
		cumtest &= Toolbox::makeTest("deleteOverflowCreditService", !ocsvtt.empty() && aa.deleteOverflowCreditService(ocsvtt.front()));

		aa.nextDay();
		cout << "WTF -=- " << Toolbox::getCurrentDate() << '\n';

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard6", aa.insertCard(cardnumber6, pin6));
		cumtest &= Toolbox::makeTest("balanceOnCard6", aa.getBalance() == (overflowVal1 + transferDaemonAmountToSend));



		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard4", aa.insertCard(cardnumber4, pin4));
		cumtest &= Toolbox::makeTest("balanceOnCard4", aa.getBalance() == balanceOnCard4);

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard5", aa.insertCard(cardnumber5, pin5));
		auto tdv6 = aa.getTransferDaemons();
		cumtest &= Toolbox::makeTest("deleteTransferDaemon6", tdv6.size() == 2 && aa.deleteTransferDaemon(tdv6.back()));

		auto tdv4 = aa.getTransferDaemons();
		bool tdvtt4 = tdv6.size() == 2;
		if (tdvtt4) {
			TransferDaemon tdte4 = tdv4.front();
			tdte4.setIsActive(true);
			tdvtt4 = aa.editTransferDaemon(tdte4);
		}
		cumtest &= Toolbox::makeTest("editTransferDaemon4", tdvtt4);

		aa.nextDay();
		aa.nextDay();

		aa.exit();
		cumtest &= Toolbox::makeTest("insertCard4", aa.insertCard(cardnumber4, pin4));
		cumtest &= Toolbox::makeTest("insertCard4", aa.getBalance() == (balanceOnCard4 + transferDaemonAmountToSend));

		cout << "Cumulative test data :=: " << cumtest << '\n';



		return cumtest;

	}
}

bool theTest() {
	initValuesForTests();
	bool res = doingTesting();
	deleteInitedData();
	assert(res);
	return res;
}
#else
bool theTest() {
	return true;
}
#endif // !debug



