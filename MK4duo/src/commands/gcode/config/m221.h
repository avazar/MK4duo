/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (c) 2019 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * mcode
 *
 * Copyright (c) 2019 Alberto Cotronei @MagoKimbra
 */

#define CODE_M221

/**
 * M221: Set extrusion percentage (M221 T0 S95)
 */
inline void gcode_M221() {

  if (commands.get_target_tool(221)) return;

  if (parser.seenval('S')) {
    extruders[tools.extruder.target]->flow_percentage = parser.value_int();
    extruders[tools.extruder.target]->refresh_e_factor();
  }
  else {
    SERIAL_SM(ECHO, "E");
    SERIAL_CHR(DIGIT(tools.extruder.target));
    SERIAL_MV(" Flow: ", extruders[tools.extruder.target]->flow_percentage);
    SERIAL_CHR('%');
    SERIAL_EOL();
  }
}
