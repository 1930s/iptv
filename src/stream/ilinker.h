/*  Copyright (C) 2014-2018 FastoGT. All right reserved.
    This file is part of iptv_cloud.
    iptv_cloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    iptv_cloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with iptv_cloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

namespace iptv_cloud {
namespace stream {

namespace elements {
class Element;
}

class ILinker {
public:
  virtual bool ElementAdd(elements::Element *elem) = 0;
  virtual bool ElementLink(elements::Element *src, elements::Element *dest) = 0;
  virtual bool ElementRemove(elements::Element *elem) = 0;
  virtual bool ElementLinkRemove(elements::Element *src,
                                 elements::Element *dest) = 0;

  virtual ~ILinker();
};

} // namespace stream
} // namespace iptv_cloud
