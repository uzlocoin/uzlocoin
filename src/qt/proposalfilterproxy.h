// Copyright (c) 2018 The Uzlocoin developers
// Copyright (c) 2018 The Curium developers
// Copyright (c) 2017-2018 The Bulwark Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_PROPOSALFILTERPROXY_H
#define BITCOIN_QT_PROPOSALFILTERPROXY_H

#include "amount.h"

#include <QDateTime>
#include <QSortFilterProxyModel>

class ProposalFilterProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ProposalFilterProxy(QObject *parent = 0);


    static const QDateTime MIN_DATE;

    static const QDateTime MAX_DATE;

    void setProposalStart(const CAmount& minimum);
    void setProposalEnd(const CAmount& minimum);
    void setTotalPaymentCount(const int& count);
    void setRemainingPaymentCount(const int& count);
    void setProposal(const QString &proposal);
    
    void setMinAmount(const CAmount& minimum);
    void setVotesNeeded(const CAmount& minimum);
    void setMinYesVotes(const CAmount& minimum);
    void setMinNoVotes(const CAmount& minimum);
    void setMinAbstainVotes(const CAmount& minimum);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;

private:
    CAmount startDate;
    CAmount endDate;
    int totalPaymentCount;
    int remainingPaymentCount;
    QString proposalName;
    CAmount minAmount;
    CAmount votesNeeded;
    CAmount minYesVotes;
    CAmount minNoVotes;
    CAmount minAbstainVotes;
};

#endif // BITCOIN_QT_PROPOSALFILTERPROXY_H
