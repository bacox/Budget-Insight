//
// Created by bacox on 02-11-19.
//

#include "../include/Transaction.h"

Transaction::Transaction(const std::string &date, const std::string &banknumber, const std::string &banknumberAgainst,
                         const std::string &valuta, long balanceBeforeMutation, long mutationAmount,
                         const std::string &journalDate, const std::string &internalCode, const std::string &globalCode,
                         const std::string &id) : date(date), banknumber(banknumber),
                                                  banknumberAgainst(banknumberAgainst), valuta(valuta),
                                                  balanceBeforeMutation(balanceBeforeMutation),
                                                  mutationAmount(mutationAmount), journalDate(journalDate),
                                                  internalCode(internalCode), globalCode(globalCode), ID(id) {}

Transaction::~Transaction() {

}

const std::string &Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const std::string &date) {
    Transaction::date = date;
}

const std::string &Transaction::getBanknumber() const {
    return banknumber;
}

void Transaction::setBanknumber(const std::string &banknumber) {
    Transaction::banknumber = banknumber;
}

const std::string &Transaction::getBanknumberAgainst() const {
    return banknumberAgainst;
}

void Transaction::setBanknumberAgainst(const std::string &banknumberAgainst) {
    Transaction::banknumberAgainst = banknumberAgainst;
}

const std::string &Transaction::getBanknumberAgainstName() const {
    return banknumberAgainstName;
}

void Transaction::setBanknumberAgainstName(const std::string &banknumberAgainstName) {
    Transaction::banknumberAgainstName = banknumberAgainstName;
}

const std::string &Transaction::getValuta() const {
    return valuta;
}

void Transaction::setValuta(const std::string &valuta) {
    Transaction::valuta = valuta;
}

long Transaction::getBalanceBeforeMutation() const {
    return balanceBeforeMutation;
}

void Transaction::setBalanceBeforeMutation(long balanceBeforeMutation) {
    Transaction::balanceBeforeMutation = balanceBeforeMutation;
}

const std::string &Transaction::getMutationValuta() const {
    return mutationValuta;
}

void Transaction::setMutationValuta(const std::string &mutationValuta) {
    Transaction::mutationValuta = mutationValuta;
}

long Transaction::getMutationAmount() const {
    return mutationAmount;
}

void Transaction::setMutationAmount(long mutationAmount) {
    Transaction::mutationAmount = mutationAmount;
}

const std::string &Transaction::getJournalDate() const {
    return journalDate;
}

void Transaction::setJournalDate(const std::string &journalDate) {
    Transaction::journalDate = journalDate;
}

const std::string &Transaction::getValutaDate() const {
    return valutaDate;
}

void Transaction::setValutaDate(const std::string &valutaDate) {
    Transaction::valutaDate = valutaDate;
}

const std::string &Transaction::getInternalCode() const {
    return internalCode;
}

void Transaction::setInternalCode(const std::string &internalCode) {
    Transaction::internalCode = internalCode;
}

const std::string &Transaction::getGlobalCode() const {
    return globalCode;
}

void Transaction::setGlobalCode(const std::string &globalCode) {
    Transaction::globalCode = globalCode;
}

const std::string &Transaction::getId() const {
    return ID;
}

void Transaction::setId(const std::string &id) {
    ID = id;
}

const std::string &Transaction::getPaymentReference() const {
    return paymentReference;
}

void Transaction::setPaymentReference(const std::string &paymentReference) {
    Transaction::paymentReference = paymentReference;
}

const std::string &Transaction::getDescription() const {
    return description;
}

void Transaction::setDescription(const std::string &description) {
    Transaction::description = description;
}

long Transaction::getStatementNumber() const {
    return statementNumber;
}

void Transaction::setStatementNumber(long statementNumber) {
    Transaction::statementNumber = statementNumber;
}

bool Transaction::operator==(const Transaction &rhs) const {
    return ID == rhs.ID;
}

bool Transaction::operator!=(const Transaction &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction) {
    os << "date: " << transaction.date << " banknumber: " << transaction.banknumber << " banknumberAgainst: "
       << transaction.banknumberAgainst << " banknumberAgainstName: " << transaction.banknumberAgainstName
       << " valuta: " << transaction.valuta << " balanceBeforeMutation: " << transaction.balanceBeforeMutation
       << " mutationValuta: " << transaction.mutationValuta << " mutationAmount: " << transaction.mutationAmount
       << " journalDate: " << transaction.journalDate << " valutaDate: " << transaction.valutaDate << " internalCode: "
       << transaction.internalCode << " globalCode: " << transaction.globalCode << " ID: " << transaction.ID
       << " paymentReference: " << transaction.paymentReference << " description: " << transaction.description
       << " statementNumber: " << transaction.statementNumber;
    return os;
}
