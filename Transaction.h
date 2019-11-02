//
// Created by bacox on 02-11-19.
//

#ifndef BUDGET_INSIGHT_TRANSACTION_H
#define BUDGET_INSIGHT_TRANSACTION_H

#include <string>

class Transaction {
    /**
     * Date
     * bankNumber
     * bankNumberSecondParty
     * nameSecond bannk number
     * Valuta
     * Balance before mutation
     * Valuta mutation
     * Mutation amount
     * Journal date
     * Valuta date
     * Internal code
     * Global Transaction code
     * Id
     * payment reference
     * Description
     * statement number
     *
     */

private:
    std::string date;
    std::string banknumber;
    std::string banknumberAgainst;
    std::string banknumberAgainstName;
    std::string valuta
    long balanceBeforeMutation;
    std::string mutationValuta;
    long mutationAmount;
    std::string journalDate;
    std::string valutaDate;
    std::string internalCode;
    std::string globalCode;
    std::string ID;
    std::string paymentReference;
    std::string description;
    long statementNumber;

public:
    Transaction(const std::string &date, const std::string &banknumber, const std::string &banknumberAgainst,
                const std::string &valuta, long balanceBeforeMutation, long mutationAmount,
                const std::string &journalDate, const std::string &internalCode, const std::string &globalCode,
                const std::string &id);

    virtual ~Transaction();

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::string &getBanknumber() const;

    void setBanknumber(const std::string &banknumber);

    const std::string &getBanknumberAgainst() const;

    void setBanknumberAgainst(const std::string &banknumberAgainst);

    const std::string &getBanknumberAgainstName() const;

    void setBanknumberAgainstName(const std::string &banknumberAgainstName);

    const std::string &getValuta() const;

    void setValuta(const std::string &valuta);

    long getBalanceBeforeMutation() const;

    void setBalanceBeforeMutation(long balanceBeforeMutation);

    const std::string &getMutationValuta() const;

    void setMutationValuta(const std::string &mutationValuta);

    long getMutationAmount() const;

    void setMutationAmount(long mutationAmount);

    const std::string &getJournalDate() const;

    void setJournalDate(const std::string &journalDate);

    const std::string &getValutaDate() const;

    void setValutaDate(const std::string &valutaDate);

    const std::string &getInternalCode() const;

    void setInternalCode(const std::string &internalCode);

    const std::string &getGlobalCode() const;

    void setGlobalCode(const std::string &globalCode);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getPaymentReference() const;

    void setPaymentReference(const std::string &paymentReference);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    long getStatementNumber() const;

    void setStatementNumber(long statementNumber);

    bool operator==(const Transaction &rhs) const;

    bool operator!=(const Transaction &rhs) const;
};


#endif //BUDGET_INSIGHT_TRANSACTION_H
