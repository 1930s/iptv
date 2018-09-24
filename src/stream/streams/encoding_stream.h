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

#include "stream/streams/src_decodebin_stream.h"

#include "stream/streams/configs/encoding_config.h"

namespace iptv_cloud {
namespace stream {
namespace streams {

class EncodingStream : public SrcDecodeBinStream {
public:
  typedef SrcDecodeBinStream base_class;
  EncodingStream(EncodingConfig *config, IStreamClient *client,
                 StreamStruct *stats);
  ~EncodingStream();

  virtual const char *ClassName() const override;

protected:
  virtual IBaseBuilder *CreateBuilder() override;

  virtual void HandleBufferingMessage(GstMessage *message) override;
  virtual gboolean HandleDecodeBinAutoplugger(GstElement *elem, GstPad *pad,
                                              GstCaps *caps) override;
  virtual void HandleDecodeBinPadAdded(GstElement *src,
                                       GstPad *new_pad) override;

  virtual GValueArray *HandleAutoplugSort(GstElement *bin, GstPad *pad,
                                          GstCaps *caps,
                                          GValueArray *factories) override;
  virtual GstAutoplugSelectResult
  HandleAutoplugSelect(GstElement *bin, GstPad *pad, GstCaps *caps,
                       GstElementFactory *factory) override;

  virtual void HandleDecodeBinElementAdded(GstBin *bin,
                                           GstElement *element) override;
  virtual void HandleDecodeBinElementRemoved(GstBin *bin,
                                             GstElement *element) override;
};

} // namespace streams
} // namespace stream
} // namespace iptv_cloud
