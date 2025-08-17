#pragma once
#include <imgui.h>
#include "imgui_internal.h"

namespace FontLoader
{
    // Returns glyph ranges including Polish letters
    static const ImWchar* GetGlyphRangesPolish()
    {
        static ImVector<ImWchar> ranges;
        if (ranges.empty())
        {
            ImFontGlyphRangesBuilder builder;
            builder.AddRanges(ImGui::GetIO().Fonts->GetGlyphRangesDefault());

            // Polish letters
            const ImWchar polish_chars[] = {
                0x0104, 0x0105, // Ą ą
                0x0106, 0x0107, // Ć ć
                0x0118, 0x0119, // Ę ę
                0x0141, 0x0142, // Ł ł
                0x0143, 0x0144, // Ń ń
                0x00D3, 0x00F3, // Ó ó
                0x015A, 0x015B, // Ś ś
                0x0179, 0x017A, // Ź ź
                0x017B, 0x017C, // Ż ż
                0
            };

            for (int i = 0; polish_chars[i]; i++) {
                builder.AddChar(polish_chars[i]);
            }

            builder.BuildRanges(&ranges);
        }
        return ranges.Data;
    }
}
