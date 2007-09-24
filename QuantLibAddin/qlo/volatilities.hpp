
/*
 Copyright (C) 2007 Ferdinando Ametrano
 Copyright (C) 2005, 2006 Eric Ehlers

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#ifndef qla_volatilities_hpp
#define qla_volatilities_hpp

#include <qlo/termstructures.hpp>

#include <ql/time/businessdayconvention.hpp>
#include <ql/types.hpp>

namespace QuantLib {
    class BlackVolTermStructure;
    class Date;
    class DayCounter;
    class Matrix;
    class Period;
}

namespace QuantLibAddin {

    OH_LIB_CLASS(BlackVolTermStructure, QuantLib::BlackVolTermStructure);

    class BlackConstantVol : public BlackVolTermStructure {
      public:
        BlackConstantVol(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& settlementDate,
            const QuantLib::Calendar& cal,
            QuantLib::Volatility volatility,
            const QuantLib::DayCounter& dayCounter,
            bool permanent);
    };

    class BlackVarianceSurface : public BlackVolTermStructure {
      public:
        BlackVarianceSurface(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            const QuantLib::Date& settlementDate,
            const QuantLib::Calendar& cal,
            const std::vector<QuantLib::Date>& dates,
            const std::vector<QuantLib::Rate>& strikes,
            const QuantLib::Matrix& vols,
            const QuantLib::DayCounter& dayCounter,
            bool permanent);
    };

    OH_OBJ_CLASS(VolatilityTermStructure, TermStructure);

    OH_OBJ_CLASS(BlackAtmVolCurve, VolatilityTermStructure);

    class AbcdAtmVolCurve: public BlackAtmVolCurve {
    public:
      AbcdAtmVolCurve(
            const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
            QuantLib::Natural settlementDays,
            const QuantLib::Calendar& cal,
            const std::vector<QuantLib::Period>& optionTenors,
            const std::vector<QuantLib::RelinkableHandle<QuantLib::Quote> > & volatilities,
            QuantLib::BusinessDayConvention bdc,
            const QuantLib::DayCounter& dc,
            bool permanent);
    };
}

#endif

