//------------------------------------------------------------------------------
/*
 This file is part of nschaind: https://github.com/nschain/nschaind
 Copyright (c) 2016-2018 NationalStoneGroup Technology Co., Ltd.
 
	nschaind is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
 
	nschaind is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
//==============================================================================

#ifndef RIPPLE_APP_TX_NSCHAINTX_H_INCLUDED
#define RIPPLE_APP_TX_NSCHAINTX_H_INCLUDED

#include <ripple/app/tx/impl/Transactor.h>

namespace ripple {

    class NSchainTx : public Transactor
    {   
    protected:        
        explicit NSchainTx(ApplyContext& ctx);

        static TER preflight(PreflightContext const& ctx);
        static TER preclaim(PreclaimContext const& ctx);
		TER doApply();	

		static bool canDispose(ApplyContext& ctx);

		static std::pair<TxStoreDBConn*, TxStore*> getTransactionDBEnv(ApplyContext& ctx);
	public:
		virtual std::pair<TER, std::string> dispose(TxStore& txStore, const STTx& tx);
    };
}

#endif
